#include "Patient.h"

Patient::Patient() : User::User()
{
	lastExtract = Extract();
}

Patient::Patient(string encryptedPassword, int role, FullName fullName,
	Date dateOfBirth, Address address):
	User::User(encryptedPassword, role, fullName, dateOfBirth, address)
{
	access = true;
	lastExtract = Extract();
}


void Patient::logInSystem(ClinicRepository& cr)
{
	while (true)
	{
		std::cout << "\n��� �� ������ �������? �������� ��������������� �����.\n"
			"1 - ���������� ���������� �������;\n"
			"2 - ������������� �������;\n"
			"3 - ����������� ��������� �������;\n"
			"4 - ����������� ������ �������;\n"
			"5 - �������� ������;\n"
			"6 - ���c������� ������������ ������;\n"
			"7 - �����.\n\n";

		int choice = getCorrectMenuInput(7);
		system("cls");
		switch (choice)
		{
		case 1:
			print();
			break;
		case 2:
			editAccountInfo();
			break;
		case 3:
			lastExtract.print();
			break;
		case 4:
			cr.printTableOfServices();
			break;
		case 5:
			buyService(cr);
			break;
		case 6:
			printUnpaidServices();
			break;
		case 7:
			return;
		}
		endCase();
	}
}

string Patient::getStringForFile()
{
	string stringForFile = "";
	stringForFile += User::getStringForFile() + " " + lastExtract.getStringForFile();

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
}

void Patient::changeExtract(string newDiagnosis, string newRecommendation)
{
	lastExtract.setDiagnosis(newDiagnosis);
	lastExtract.setRecommendations(newRecommendation);
	lastExtract.setMap(mapOfUnpaidServices);

	mapOfUnpaidServices.clear();
	totalPrice = 0;
}


void Patient::editAccountInfo()
{
	while (true)
	{
		std::cout << "\n��� �� ������ �������������? �������� ��������������� �����.\n"
			"1 - ������ ���;\n"
			"2 - ���� ��������;\n"
			"3 - �����;\n"
			"4 - �����.\n\n";

		int choice = getCorrectMenuInput(4);
		system("cls");
		switch (choice)
		{
		case 1:
			std::cout << "������� ������ ���\n";
			fullName.surname = getCorrectWordInput(std::cin, "�������: ");
			fullName.name = getCorrectWordInput(std::cin, "���: ");
			fullName.patronymic = getCorrectWordInput(std::cin, "��������: ");
			return;
		case 2:
			std::cout << "������� ���� �������� (��.��.����)\n";
			dateOfBirth = getCorrectDateOfBirth(std::cin, 2);
			return;
		case 3:
			std::cout << "������� ����� ����������\n";
			address.city = getCorrectWordInput(std::cin, "�����: ");
			address.street = getCorrectStringInput(std::cin, "�����: ");
			address.houseNumber = getCorrectPositiveInteger(std::cin, "����� ����: ");
			address.flatNumber = getCorrectFlatNumber(std::cin);
			return;
		case 4:
			return;
		}
		endCase();
	}
}

void Patient::buyService(ClinicRepository cr)
{
	std::cout << "��� ����, ����� ����� ������� ������.\n";
	while (true)
	{
		std::cout << "������� �������� ������, ������� ������ ����������.\n";
		string serviceToBuy = getCorrectStringInput(std::cin, "��������: ");
		if (serviceToBuy == " ") break;

		double servicePrice = cr.getPriceByName(serviceToBuy);
		if (servicePrice != 0)
		{
			mapOfUnpaidServices.insert(std::pair<string, double>(serviceToBuy, servicePrice));
			totalPrice += servicePrice;
		}
		else std::cout << "���� ������� �� ������������� ����� � ����� ���������.\n";
	}
}

void Patient::printUnpaidServices()
{
	if (totalPrice != 0)
	{
		std::cout << std::setw(20) << "������" << "   " << "����" << std::endl;

		for (const auto& serviceInfo : mapOfUnpaidServices)
		{
			std::cout << std::setw(20) << serviceInfo.first << "   " << serviceInfo.second << std::endl;
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
		patient.lastExtract;
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
