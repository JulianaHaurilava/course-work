#include "Administrator.h"

string Administrator::getCorrectLogin(std::istream& s, const char* message, Repository& r)
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
				role != 2)
			{
				throw -1;
			}
			if (role == 1) throw false;

			return adminInput;
		}
		catch (bool)
		{
			std::cin.clear();
			std::cout << "Введенные данные некорректны! Пользователь с таким логином" <<
				"не зарегистрирован в системе.\n Повторите ввод.\n\n";
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

void Administrator::logInSystem(Repository& r)
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
			workWithServices(r);
			break;
		case 2: 
			workWithAccounts(r);
			break;
		case 3: 
			return;
		}
		endCase();
	}
}

void Administrator::workWithAccounts(Repository& r)
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
			std::cout << "Персонал клиники \"" << r.clinicName << "\"\n\n";
			r.printAllAccounts(r.vectorOfAllDoctors);
			break;
		case 2:
			std::cout << "Пациенты клиники \"" << r.clinicName << "\"\n\n";
			r.printAllAccounts(r.vectorOfAllPatients);
			break;
		case 3:
			std::cout << "Аккаунты, которые ждут верификации\n\n";
			r.printAllAccounts(r.vectorOfNotVerifiedDoctors);
			break;
		case 4:
		{
			string loginToVerify = getCorrectLogin(std::cin, 
				"Введите логин пользователя, которого хотите верифицировать:\n", r);
			verifyAccount(loginToVerify, r);
			break;
		}
		case 5:
		{
			string loginToDeactivate = getCorrectLogin(std::cin,
				"Введите логин пользователя, аккаунт которого хотите деактивировать:\n", r);
			deactivateAccount(loginToDeactivate, r);
			break;
		}
		case 6:
		{
			string loginToFind = getCorrectLogin(std::cin,
				"Введите логин верифицированного пользователя, аккаунт которого хотите найти:\n", r);
			printAccountByLogin(loginToFind, r);
			break;
		}
		case 7:
			return;
		}
		endCase();
	}
}

void Administrator::workWithServices(Repository& r)
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
			r.printTableOfServices();
			break;
		case 2:
		{
			std::cout << "Введите информацию о новой услуге\n";
			string name = getCorrectStringInput(std::cin, "Название услуги: ");
			double price = getCorrectPositiveDouble(std::cin, "Цена: ");
			r.addNewService(name, price);
			break;
		}
		case 3:
		{
			std::cout << "Введите название услуги, которую хотите удалить\n";
			string name = getCorrectStringInput(std::cin, "Название услуги: ");
			r.deleteService(name);
			break;
		}
		case 4:
		{
			std::cout << "Введите название услуги, информацию о которой хотите редактировать\n";
			string name = getCorrectStringInput(std::cin, "Название услуги: ");
			r.editService(name);
			break;
		}
		case 5:
		{
			std::cout << "Введите название услуги, цену которой хотите узнать\n";
			string name = getCorrectStringInput(std::cin, "Название услуги: ");
			double foundPrice = r.getPriceByName(name);
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

void Administrator::verifyAccount(string loginToVerify, Repository& r)
{
	int indexToVerify = r.getNonVerifiedIndexByLogin(loginToVerify);
	if (indexToVerify == -1)
	{
		std::cout << "Аккаунт с таким логином не существует!\n";
		return;
	}

	int role = stoi(loginToVerify.substr(0, 2));

	r.vectorOfNotVerifiedDoctors[indexToVerify].changeAccess();
	r.vectorOfAllDoctors.push_back(r.vectorOfNotVerifiedDoctors[indexToVerify]);
	r.vectorOfNotVerifiedDoctors.erase(r.vectorOfNotVerifiedDoctors.begin() + indexToVerify);
}

void Administrator::deactivateAccount(string loginToDeactivate, Repository& r)
{
	int indexToVerify = r.getIndexByLogin(loginToDeactivate);

	int role = stoi(login.substr(0, 2));

	switch (role)
	{
	case 1:
		r.vectorOfAllDoctors.erase(r.vectorOfAllDoctors.begin() + indexToVerify);
		return;
	case 2:
		r.vectorOfAllPatients.erase(r.vectorOfAllPatients.begin() + indexToVerify);
		return;
	default:
		std::cout << "Аккаунт с таким логином не существует!\n";
		return;
	}
}

void Administrator::printAccountByLogin(string loginToFind, Repository& r)
{
	int index = r.getIndexByLogin(loginToFind);

	int role = stoi(login.substr(0, 2));

	switch (role)
	{
	case 1:
		r.vectorOfAllDoctors[index].print();
		return;
	case 2:
		r.vectorOfAllPatients[index].print();
		return;
	default:
		std::cout << "Аккаунт с таким логином не существует!\n";
		return;
	}
}
