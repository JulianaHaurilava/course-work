#include "Administrator.h"

string Administrator::getCorrectLogin(std::istream& s, const char* message)
{
	string adminInput;
	while (true)
	{
		try
		{
			std::cout << message;
			getline(std::cin, adminInput);

			int role = stoi(adminInput.substr(0, 2));
			if (adminInput.length() != 16 ||
				!(role == 2 || role == 3))
			{
				throw -1;
			}

			return adminInput;
		}
		catch (std::invalid_argument)
		{
			std::cin.clear();
			std::cout << "Введенные данные некорректны! Введен неверный логин.\n" <<
				"Повторите ввод.\n\n";
		}
		catch (int)
		{
			std::cin.clear();
			std::cout << "Введенные данные некорректны! Введен неверный логин.\n" <<
				"Повторите ввод.\n\n";
		}
	}
}

Administrator::Administrator()
{
	login = "0107112022134542";
	encryptedPassword = "Qi1Yld";
	access = true;
}

Administrator::~Administrator()
{

}

void Administrator::logInSystem(AccountRepository<Doctor>& dr, AccountRepository<Doctor>& ndr,
	AccountRepository<Patient>& pr, ClinicRepository& cr)
{
	while (true)
	{
		std::cout << "\nЧто вы хотите сделать? Выберите соответствующее число.\n"
			"1 - работа с услугами клинки;\n"
			"2 - работа с аккаунтами;\n"
			"3 - выйти.\n\n";

		int choice = getCorrectMenuInput(3);
		system("cls");
		switch (choice)
		{
		case 1:
			workWithServices(cr);
			break;
		case 2: 
			workWithAccounts(dr, ndr, pr);
			break;
		case 3: 
			return;
		}
		endCase();
	}
}

void Administrator::workWithAccounts(AccountRepository<Doctor>& dr, AccountRepository<Doctor>& ndr,
	AccountRepository<Patient>& pr)
{
	while (true)
	{
		std::cout << "\nЧто вы хотите сделать? Выберите соответствующее число.\n"
			"1 - просмотреть информацию обо всех врачах;\n"
			"2 - просмотреть информацию обо всех пациентах;\n"
			"3 - просмотреть информацию обо всех неверефецированных аккаунтах;\n"
			"4 - верифицировать аккаунт;\n"
			"5 - деактивировать аккаунт;\n"
			"6 - найти аккаунт по логину;\n"
			"7 - выйти.\n\n";

		int choice = getCorrectMenuInput(7);
		system("cls");
		switch (choice)
		{
		case 1:
			std::cout << "Персонал клиники\n\n";
			dr.printAllAccounts();
			break;
		case 2:
			std::cout << "Пациенты клиники\n\n";
			pr.printAllAccounts();
			break;
		case 3:
			std::cout << "Аккаунты, которые ждут верификации\n\n";
			ndr.printAllAccounts();
			break;
		case 4:
		{
			string loginToVerify = getCorrectLogin(std::cin, 
				"Введите логин пользователя, которого хотите верифицировать:\n");
			verifyAccount(loginToVerify, ndr, dr);
			break;
		}
		case 5:
		{
			string loginToDeactivate = getCorrectLogin(std::cin,
				"Введите логин пользователя, аккаунт которого хотите деактивировать:\n");

			deactivateAccount(loginToDeactivate, dr, pr);
			break;
		}
		case 6:
		{
			string loginToPrint = getCorrectLogin(std::cin,
				"Введите логин пользователя, аккаунт которого хотите найти:\n");

			printAccountByLogin(loginToPrint, dr, pr);
			break;
		}
		case 7:
			return;
		}
		endCase();
	}
}

void Administrator::workWithServices(ClinicRepository& cr)
{
	while (true)
	{
		std::cout << "\nЧто вы хотите сделать? Выберите соответствующее число.\n"
			"1 - просмотреть информацию обо всех услугах;\n"
			"2 - добавить новую услугу;\n"
			"3 - удалить услугу;\n"
			"4 - редактировать данные об услуге;\n"
			"5 - узнать цену по названию услуги;\n"
			"6 - выйти.\n\n";

		int choice = getCorrectMenuInput(6);
		system("cls");
		switch (choice)
		{
		case 1:
			cr.printTableOfServices();
			break;
		case 2:
		{
			std::cout << "Введите информацию о новой услуге\n";
			string name = getCorrectStringInput(std::cin, "Название услуги: ");
			double price = getCorrectPositiveDouble(std::cin, "Цена: ");
			cr.addNewService(name, price);
			break;
		}
		case 3:
		{
			std::cout << "Введите название услуги, которую хотите удалить\n";
			string name = getCorrectStringInput(std::cin, "Название услуги: ");
			cr.deleteService(name);
			break;
		}
		case 4:
		{
			std::cout << "Введите название услуги, информацию о которой хотите редактировать\n";
			string name = getCorrectStringInput(std::cin, "Название услуги: ");
			cr.editService(name);
			break;
		}
		case 5:
		{
			std::cout << "Введите название услуги, цену которой хотите узнать\n";
			string name = getCorrectStringInput(std::cin, "Название услуги: ");
			double foundPrice = cr.getPriceByName(name);
			if (foundPrice != 0)
			{
				std::cout << "Цена: " << foundPrice << std::endl;
			}
			else std::cout << "Услуга не найдена!\n";
			break;
		}
		case 6:
			return;
		}
		endCase();
	}
}

void Administrator::deactivateAccount(string loginToDeactivate, AccountRepository<Doctor>& dr,
	AccountRepository<Patient>& pr)
{
	int role = stoi(loginToDeactivate.substr(0, 2));

	switch (role)
	{
	case 2:
		dr.deleteAccount(loginToDeactivate);
		break;
	case 3:
		pr.deleteAccount(loginToDeactivate);
		break;
	}
}

void Administrator::printAccountByLogin(string loginToPrint, AccountRepository<Doctor>& dr,
	AccountRepository<Patient>& pr)
{
	int role = stoi(loginToPrint.substr(0, 2));

	switch (role)
	{
	case 2:
		dr.printAccountByLogin(loginToPrint);
		break;
	case 3:
		pr.printAccountByLogin(loginToPrint);
		break;
	}
}

void Administrator::verifyAccount(string loginToVerify, AccountRepository<Doctor>& ndr,
	AccountRepository<Doctor>& dr)
{
	Doctor doctorToVerify = ndr.changeAccess(loginToVerify);
	if (doctorToVerify.getAccess())
	{
		dr.addNewAccount(doctorToVerify);
		ndr.deleteAccount(loginToVerify);
	}
	else std::cout << "Аккаунт с таким логином не зарегистрирован в системе!\n";
}
