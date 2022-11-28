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
		std::cout << "\nЧто вы хотите сделать? Выберите соответствующее число.\n"
			"1 - посмотреть информацию профиля;\n"
			"2 - редактировать профиль;\n"
			"3 - просмотреть последнюю выписку;\n"
			"4 - просмотреть услуги клиники;\n"
			"5 - приобрести услуги;\n"
			"6 - выйти.\n\n";

		int choice = getCorrectMenuInput(6);
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
			printLastExtract();
			break;
		case 4:
			cr.printTableOfServices();
			break;
		case 5:
			buyService();
			break;
		case 6:
			return;
		}
		endCase();
	}
}

string Patient::getStringForFile()
{
	return  User::getStringForFile() + " " + lastExtract.getStringForFile();
}

void Patient::print()
{
	User::print();
}

void Patient::printLastExtract()
{
	lastExtract.print();
}

void Patient::editAccountInfo()
{
	while (true)
	{
		std::cout << "\nЧто вы хотите редактировать? Выберите соответствующее число.\n"
			"1 - полное имя;\n"
			"2 - дата рождения;\n"
			"3 - адрес;\n"
			"4 - выйти.\n\n";

		int choice = getCorrectMenuInput(4);
		system("cls");
		switch (choice)
		{
		case 1:
			std::cout << "Введите полное имя\n";
			fullName.surname = getCorrectWordInput(std::cin, "Фамилия: ");
			fullName.name = getCorrectWordInput(std::cin, "Имя: ");
			fullName.patronymic = getCorrectWordInput(std::cin, "Отчество: ");
			break;
		case 2:
			std::cout << "Введите дату рождения (дд.мм.гггг)\n";
			dateOfBirth = getCorrectDateOfBirth(std::cin, 2);
			break;
		case 3:
			std::cout << "Введите адрес проживания\n";
			address.city = getCorrectWordInput(std::cin, "Город: ");
			address.street = getCorrectStringInput(std::cin, "Улица: ");
			address.houseNumber = getCorrectPositiveInteger(std::cin, "Номер дома: ");
			address.flatNumber = getCorrectFlatNumber(std::cin);
			break;
		case 4:
			return;
		}
		endCase();
	}
}

void Patient::buyService()
{
	std::cout << "Для того, чтобы выйти введите пустую строку.\n";
	while (true)
	{
		std::cout << "Введите название услуги, которую хотите приобрести.";
	}
}

std::istream& operator >> (std::istream& in, Patient& patient)
{
	return in >> patient.login >> patient.encryptedPassword >> patient.access >>
		patient.fullName >> patient.dateOfBirth >> patient.address >>
		patient.lastExtract;
}
