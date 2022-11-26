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
			std::cout << "��������� ������ �����������! ������������ � ����� �������" <<
				"�� ��������������� � �������.\n ��������� ����.\n\n";
		}
		catch (std::invalid_argument)
		{
			std::cin.clear();
			std::cout << "��������� ������ �����������! ������ �������� �����.\n" <<
				"��������� ����.\n\n";
		}
		catch (int)
		{
			std::cin.clear();
			std::cout << "��������� ������ �����������! ������ �������� �����.\n" <<
				"��������� ����.\n\n";
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
		std::cout << "\n��� �� ������ �������? �������� ��������������� �����.\n"
			"1 - ������ � �������� ������;\n"
			"2 - ������ � ����������;\n"
			"3 - �����.\n\n";

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
		std::cout << "\n��� �� ������ �������? �������� ��������������� �����.\n"
			"1 - ����������� ���������� ��� ���� ������;\n"
			"2 - ����������� ���������� ��� ���� ���������;\n"
			"3 - ����������� ���������� ��� ���� ������������������ ���������;\n"
			"4 - �������������� �������;\n"
			"5 - �������������� �������;\n"
			"6 - ����� ������� �� ������;\n"
			"7 - �����.\n\n";

		int choice = getCorrectMenuInput(7);
		system("cls");
		switch (choice)
		{
		case 1:
			std::cout << "�������� ������� \"" << r.clinicName << "\"\n\n";
			r.printAllAccounts(r.vectorOfAllDoctors);
			break;
		case 2:
			std::cout << "�������� ������� \"" << r.clinicName << "\"\n\n";
			r.printAllAccounts(r.vectorOfAllPatients);
			break;
		case 3:
			std::cout << "��������, ������� ���� �����������\n\n";
			r.printAllAccounts(r.vectorOfNotVerifiedDoctors);
			break;
		case 4:
		{
			string loginToVerify = getCorrectLogin(std::cin, 
				"������� ����� ������������, �������� ������ ��������������:\n", r);
			verifyAccount(loginToVerify, r);
			break;
		}
		case 5:
		{
			string loginToDeactivate = getCorrectLogin(std::cin,
				"������� ����� ������������, ������� �������� ������ ��������������:\n", r);
			deactivateAccount(loginToDeactivate, r);
			break;
		}
		case 6:
		{
			string loginToFind = getCorrectLogin(std::cin,
				"������� ����� ����������������� ������������, ������� �������� ������ �����:\n", r);
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
		std::cout << "\n��� �� ������ �������? �������� ��������������� �����.\n"
			"1 - ����������� ���������� ��� ���� �������;\n"
			"2 - �������� ����� ������;\n"
			"3 - ������� ������;\n"
			"4 - ������������� ������ �� ������;\n"
			"5 - ������ ���� �� �������� ������;\n"
			"6 - �����.\n\n";

		int choice = getCorrectMenuInput(6);
		system("cls");
		switch (choice)
		{
		case 1:
			r.printTableOfServices();
			break;
		case 2:
		{
			std::cout << "������� ���������� � ����� ������\n";
			string name = getCorrectStringInput(std::cin, "�������� ������: ");
			double price = getCorrectPositiveDouble(std::cin, "����: ");
			r.addNewService(name, price);
			break;
		}
		case 3:
		{
			std::cout << "������� �������� ������, ������� ������ �������\n";
			string name = getCorrectStringInput(std::cin, "�������� ������: ");
			r.deleteService(name);
			break;
		}
		case 4:
		{
			std::cout << "������� �������� ������, ���������� � ������� ������ �������������\n";
			string name = getCorrectStringInput(std::cin, "�������� ������: ");
			r.editService(name);
			break;
		}
		case 5:
		{
			std::cout << "������� �������� ������, ���� ������� ������ ������\n";
			string name = getCorrectStringInput(std::cin, "�������� ������: ");
			double foundPrice = r.getPriceByName(name);
			if (foundPrice != 0)
			{
				std::cout << "����: " << foundPrice << std::endl;
			}
			else std::cout << "������ �� �������!\n";
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
		std::cout << "������� � ����� ������� �� ����������!\n";
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
		std::cout << "������� � ����� ������� �� ����������!\n";
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
		std::cout << "������� � ����� ������� �� ����������!\n";
		return;
	}
}
