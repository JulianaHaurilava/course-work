#include "Patient.h"

Patient::Patient() : User::User()
{
	lastExtract = Extract();
	dateOfReception = Date();
	timeOfReception = Time();
}

Patient::Patient(string encryptedPassword, int role, FullName fullName,
	Date dateOfBirth, Address address):
	User::User(encryptedPassword, role, fullName, dateOfBirth, address)
{
	access = true;
	lastExtract = Extract();
}


void Patient::logInSystem(ClinicRepository& cr, AccountRepository<Patient>& pr)
{
	while (true)
	{
		std::cout << "��� �� ������ �������? �������� ��������������� �����.\n"
			"1 - ���������� ���������� �������;\n"
			"2 - ������������� �������;\n"
			"3 - ����������� ��������� �������;\n"
			"4 - ����������� ������ �������;\n"
			"5 - �������� ������;\n"
			"6 - ����������� ���������� � ������ �� �����;\n"
			"7 - �����.\n\n";

		int choice = chps::getCorrectMenuInput(7);
		system("cls");
		switch (choice)
		{
		case 1:
			// �������� ���������� � ������������
			print();
			break;
		case 2:
			// ������������� �������� ������������
			if (editAccountInfo())
				pr.updateRepository();
			break;
		case 3:
			// �������� ���������� � ��������� �������
			lastExtract.print();
			break;
		case 4:
		{
			// �������� ���� ����� �������
			std::cout << "\n��� ������� ������?\n"
				"1 - �� ��������;\n"
				"2 - ������ ��������.\n\n";

			int choice = chps::getCorrectMenuInput(2);

			if (choice == 1)
				cr.printTableOfServices(true);
			else cr.printTableOfServices(false);
			break;
		}
		case 5:
			// ����� �����
			if (mapOfUnpaidServices.empty())
			{
				if (makeOrder(cr))
				{
					makeReception();
					pr.updateRepository();
				}
			}
			else std::cout << "����� ��� ��������!\n\n" <<
				"���� ������: " << dateOfReception << std::endl <<
				"����� ������: " << timeOfReception << std::endl << std::endl;
			break;
		case 6:
			// �������� ���� ������������ �����
			printUnpaidServices();
			break;
		case 7:
			return;
		}
		chps::endCase();
	}
}

Time Patient::getTimeOfReception()
{
	return timeOfReception;
}

string Patient::getStringForFile()
{
	string stringForFile = "";
	stringForFile += User::getStringForFile() + " " + dateOfReception.getStringForFile() + " " + 
		timeOfReception.getStringForFile() + " " + lastExtract.getStringForFile();

	if (!mapOfUnpaidServices.empty())
	{
		stringForFile += "u ";
		for (const auto& serviceInfo : mapOfUnpaidServices)
		{
			stringForFile += serviceInfo.first + " " + std::to_string(serviceInfo.second) + " ";
		}

		stringForFile.pop_back();
		stringForFile.push_back('\n');
	}
	
	return stringForFile;

}

void Patient::print()
{
	User::print();
}

void Patient::printInfoForDoctor()
{
	std::cout << "�.�.�: " << fullName << std::endl;
	std::cout << "���� ��������: " << dateOfBirth << std::endl << std::endl;


	lastExtract.printExtractForDoctor();
	printUnpaidServicesForDoctor();
}

void Patient::changeExtract(string newDiagnosis, string newRecommendation)
{
	lastExtract.setDiagnosis(newDiagnosis);
	lastExtract.setRecommendations(newRecommendation);
	lastExtract.setMap(mapOfUnpaidServices);

	mapOfUnpaidServices.clear();
	totalPrice = 0;
}

void Patient::makeReport()
{
	std::ofstream fout;
	fout.open(REPORT_FILE_NAME, std::ios::app);

	if (!fout.is_open())
	{
		std::cout << "\n������ �������� �����!\n";
		return;
	}

	fout << fullName << '\n';
	for (auto& serviceInfo : mapOfUnpaidServices)
	{
		fout << std::setw(25) << serviceInfo.first << std::setw(15) << 
			std::to_string(serviceInfo.second) << '\n';
	}
	fout << '\n';
	fout.close();

	fout.close();
}

void Patient::printUnpaidServicesForDoctor()
{
	if (totalPrice != 0)
	{
		std::cout << "���������� ������" << std::endl;
		for (const auto& serviceInfo : mapOfUnpaidServices)
		{
			std::cout << serviceInfo.first << std::endl;
		}
		std::cout << std::endl;
	}
}

void Patient::makeReception()
{
	dateOfReception = chps::getCorrectDateOfReseption(std::cin);
	timeOfReception = chps::getCorrectTimeOfReseption(std::cin);
}


bool Patient::editAccountInfo()
{
	while (true)
	{
		std::cout << "��� �� ������ �������������? �������� ��������������� �����.\n"
			"1 - ������ ���;\n"
			"2 - ���� ��������;\n"
			"3 - �����;\n"
			"4 - �����.\n\n";

		int choice = chps::getCorrectMenuInput(4);
		system("cls");
		switch (choice)
		{
		case 1:
			std::cout << "������� ������ ���\n";
			fullName.surname = chps::getCorrectWordInput(std::cin, "�������: ");
			fullName.name = chps::getCorrectWordInput(std::cin, "���: ");
			fullName.patronymic = chps::getCorrectWordInput(std::cin, "��������: ");

			
			return true;
		case 2:
			std::cout << "������� ���� �������� (��.��.����)\n";
			dateOfBirth = chps::getCorrectDateOfBirth(std::cin, 2);
			return true;
		case 3:
			std::cout << "������� ����� ����������\n";
			address.city = chps::getCorrectWordInput(std::cin, "�����: ");
			address.street = chps::getCorrectStringInput(std::cin, "�����: ");
			address.houseNumber = chps::getCorrectPositiveInteger(std::cin, "����� ����: ");
			address.flatNumber = chps::getCorrectFlatNumber(std::cin);
			return true;
		case 4:
			return false;
		}
		chps::endCase();
	}
}

bool Patient::makeOrder(ClinicRepository cr)
{
	std::cout << "��� ����, ����� ����� ������� ������ ������.\n\n";
	bool gotService = false; // ������� �� ������������ ������

	// ����� �����
	while (true)
	{
		std::cout << "������� �������� ������, ������� ������ ����������.\n";
		string serviceToBuy = chps::getCorrectStringInputEsc(std::cin, "��������: "); // ���� �������� ������

		// ����� ����� ����� ����� ��������������, ���� �� ������� ������ ������
		if (serviceToBuy == "") 
			break;

		// ��������� ���� ������ �� ��������
		double servicePrice = cr.getPriceByName(serviceToBuy);

		//���������� ������ � ������� ������������ ����� � ������� �������� ���������
		if (servicePrice != 0)
		{
			mapOfUnpaidServices.insert(std::pair<string, double>(serviceToBuy, servicePrice));
			totalPrice += servicePrice;
			gotService = true;
		}
		else std::cout << "���� ������� �� ������������� ����� � ����� ���������.\n";
	}
	return gotService;
}

void Patient::printUnpaidServices()
{
	if (totalPrice != 0)
	{
		std::cout << "���� ������: " << dateOfReception << std::endl <<
			"����� ������: " << timeOfReception << std::endl << std::endl;

		std::cout << std::setw(25) << "������" << "   " << "����" << std::endl << std::endl;

		for (const auto& serviceInfo : mapOfUnpaidServices)
		{
			std::cout << std::setw(25) << serviceInfo.first << "   " << serviceInfo.second << " BYN" << std::endl;
		}

		std::cout << std::endl;
		std::cout << "�������� ����: " << totalPrice << " BYN" << std::endl;


	}
	else std::cout << "\n������ �� ��������!\n";
}


std::istream& operator >> (std::istream& in, Patient& patient)
{
	in >> patient.login >> patient.encryptedPassword >> patient.access >>
		patient.fullName >> patient.dateOfBirth >> patient.address >> 
		patient.dateOfReception >> patient.timeOfReception >> patient.lastExtract;
	patient.totalPrice = 0;

	if (in.peek() == 'u')
	{
		char nextChar = in.get();
		int i = 0;
		while (nextChar != '\n')
		{
			string buff;
			string serviceName;
			double servicePrice;
			in >> buff;

			while (buff[0] < 48 || buff[0] > 58)
			{
				serviceName += buff + " ";
				in >> buff;
			}
			serviceName.pop_back();
			servicePrice = stod(buff);
			patient.totalPrice += servicePrice;
			patient.mapOfUnpaidServices.insert({ serviceName, servicePrice });
			nextChar = in.peek();
		}
		in.get();
	}
	return in;
}
