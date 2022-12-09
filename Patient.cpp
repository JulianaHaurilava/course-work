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


void Patient::logInSystem(ClinicRepository& cr, AccountRepository<Patient>& pr)
{
	while (true)
	{
		std::cout << "Что вы хотите сделать? Выберите соответствующее число.\n"
			"1 - посмотреть информацию профиля;\n"
			"2 - редактировать профиль;\n"
			"3 - просмотреть последнюю выписку;\n"
			"4 - просмотреть услуги клиники;\n"
			"5 - заказать услуги;\n"
			"6 - проcмотреть неоплаченные услуги;\n"
			"7 - выйти.\n\n";

		int choice = chps::getCorrectMenuInput(7);
		system("cls");
		switch (choice)
		{
		case 1:
			print();
			break;
		case 2:
			if (editAccountInfo())
				pr.updateRepository();
			break;
		case 3:
			lastExtract.print();
			break;
		case 4:
			cr.printTableOfServices();
			break;
		case 5:
			if (buyService(cr)) pr.updateRepository(); 
			break;
		case 6:
			printUnpaidServices();
			break;
		case 7:
			return;
		}
		chps::endCase();
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
	std::cout << "Ф.И.О: " << fullName << std::endl;
	std::cout << "Дата рождения: " << dateOfBirth << std::endl << std::endl;


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
		std::cout << "\nОшибка открытия файла!\n";
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
		std::cout << "Заказанные услуги" << std::endl;
		for (const auto& serviceInfo : mapOfUnpaidServices)
		{
			std::cout << serviceInfo.first << std::endl;
		}
		std::cout << std::endl;
	}
}


bool Patient::editAccountInfo()
{
	while (true)
	{
		std::cout << "Что вы хотите редактировать? Выберите соответствующее число.\n"
			"1 - полное имя;\n"
			"2 - дата рождения;\n"
			"3 - адрес;\n"
			"4 - выйти.\n\n";

		int choice = chps::getCorrectMenuInput(4);
		system("cls");
		switch (choice)
		{
		case 1:
			std::cout << "Введите полное имя\n";
			fullName.surname = chps::getCorrectWordInput(std::cin, "Фамилия: ");
			fullName.name = chps::getCorrectWordInput(std::cin, "Имя: ");
			fullName.patronymic = chps::getCorrectWordInput(std::cin, "Отчество: ");

			
			return true;
		case 2:
			std::cout << "Введите дату рождения (дд.мм.гггг)\n";
			dateOfBirth = chps::getCorrectDateOfBirth(std::cin, 2);
			return true;
		case 3:
			std::cout << "Введите адрес проживания\n";
			address.city = chps::getCorrectWordInput(std::cin, "Город: ");
			address.street = chps::getCorrectStringInput(std::cin, "Улица: ");
			address.houseNumber = chps::getCorrectPositiveInteger(std::cin, "Номер дома: ");
			address.flatNumber = chps::getCorrectFlatNumber(std::cin);
			return true;
		case 4:
			return false;
		}
		chps::endCase();
	}
}

bool Patient::buyService(ClinicRepository cr)
{
	std::cout << "Для того, чтобы выйти введите пустую строку.\n\n";
	bool gotService = false;
	while (true)
	{
		std::cout << "Введите название услуги, которую хотите приобрести.\n";
		string serviceToBuy = chps::getCorrectStringInputEsc(std::cin, "Название: ");
		if (serviceToBuy == "") break;

		double servicePrice = cr.getPriceByName(serviceToBuy);
		if (servicePrice != 0)
		{
			mapOfUnpaidServices.insert(std::pair<string, double>(serviceToBuy, servicePrice));
			totalPrice += servicePrice;
			gotService = true;
		}
		else std::cout << "Наша клиника не предоставляет услуг с таким названием.\n";
	}
	return gotService;
}

void Patient::printUnpaidServices()
{
	if (totalPrice != 0)
	{
		std::cout << std::setw(25) << "Услуги" << "   " << "Цена" << std::endl << std::endl;

		for (const auto& serviceInfo : mapOfUnpaidServices)
		{
			std::cout << std::setw(25) << serviceInfo.first << "   " << serviceInfo.second << " BYN" << std::endl;
		}

		std::cout << std::endl;
		std::cout << "Итоговая цена: " << totalPrice << " BYN" << std::endl;
	}
	else std::cout << "\nУслуги не заказаны!\n";
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
