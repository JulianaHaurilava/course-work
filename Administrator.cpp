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

void Administrator::logInSystem(AccountRepository<Doctor>& dr, AccountRepository<Doctor>& ndr,
	AccountRepository<Patient>& pr, ClinicRepository& cr)
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
			std::cout << "�������� �������\n\n";
			dr.printAllAccounts();
			break;
		case 2:
			std::cout << "�������� �������\n\n";
			pr.printAllAccounts();
			break;
		case 3:
			std::cout << "��������, ������� ���� �����������\n\n";
			ndr.printAllAccounts();
			break;
		case 4:
		{
			string loginToVerify = getCorrectLogin(std::cin, 
				"������� ����� ������������, �������� ������ ��������������:\n");
			verifyAccount(loginToVerify, ndr, dr);
			break;
		}
		case 5:
		{
			string loginToDeactivate = getCorrectLogin(std::cin,
				"������� ����� ������������, ������� �������� ������ ��������������:\n");
			deactivateAccount(loginToDeactivate, dr, pr);
			break;
		}
		case 6:
		{
			string loginToFind = getCorrectLogin(std::cin,
				"������� ����� ����������������� ������������, ������� �������� ������ �����:\n");
			printAccountByLogin(loginToFind, dr, pr);
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
			cr.printTableOfServices();
			break;
		case 2:
		{
			std::cout << "������� ���������� � ����� ������\n";
			string name = getCorrectStringInput(std::cin, "�������� ������: ");
			double price = getCorrectPositiveDouble(std::cin, "����: ");
			cr.addNewService(name, price);
			break;
		}
		case 3:
		{
			std::cout << "������� �������� ������, ������� ������ �������\n";
			string name = getCorrectStringInput(std::cin, "�������� ������: ");
			cr.deleteService(name);
			break;
		}
		case 4:
		{
			std::cout << "������� �������� ������, ���������� � ������� ������ �������������\n";
			string name = getCorrectStringInput(std::cin, "�������� ������: ");
			cr.editService(name);
			break;
		}
		case 5:
		{
			std::cout << "������� �������� ������, ���� ������� ������ ������\n";
			string name = getCorrectStringInput(std::cin, "�������� ������: ");
			double foundPrice = cr.getPriceByName(name);
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

void Administrator::verifyAccount(string loginToVerify, AccountRepository<Doctor>& ndr,
	AccountRepository<Doctor>& dr)
{
	/*int indexToVerify = ndr.getIndexByLogin(loginToVerify);
	if (indexToVerify == -1)
	{
		std::cout << "������� � ����� ������� �� ��������������� � �������!\n";
		return;
	}

	ndr.vectorOfAccounts[indexToVerify].changeAccess();
	dr.vectorOfAccounts.push_back(ndr.vectorOfAccounts[indexToVerify]);
	ndr.vectorOfAccounts.erase(ndr.vectorOfAccounts.begin() + indexToVerify);*/
}

void Administrator::deactivateAccount(string loginToDeactivate, AccountRepository<Doctor>& dr,
	AccountRepository<Patient>& pr)
{
	/*int role = stoi(login.substr(0, 2));

	switch (role)
	{
	case 2:
	{
		int indexToVerify = dr.getIndexByLogin(loginToDeactivate);
		dr.vectorOfAccounts.erase(dr.vectorOfAccounts.begin() + indexToVerify);
		return;
	}
	case 3:
	{
		int indexToVerify = pr.getIndexByLogin(loginToDeactivate);
		pr.vectorOfAccounts.erase(pr.vectorOfAccounts.begin() + indexToVerify);
		return;
	}
	default:
		std::cout << "������� � ����� ������� �� ��������������� � �������!\n";
		return;
	}*/
}

void Administrator::printAccountByLogin(string loginToFind, AccountRepository<Doctor>& dr,
	AccountRepository<Patient>& pr)
{
	/*int role = stoi(login.substr(0, 2));

	switch (role)
	{
	case 2:
	{
		int index = dr.getIndexByLogin(loginToFind);
		dr.vectorOfAccounts[index].print();
		return;
	}
	case 3:
	{
		int index = pr.getIndexByLogin(loginToFind);
		pr.vectorOfAccounts[index].print();
		return;
	}
	default:
		std::cout << "������� � ����� ������� �� ����������!\n";
		return;
	}*/
}
