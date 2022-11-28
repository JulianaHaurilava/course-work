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
			string loginToPrint = getCorrectLogin(std::cin,
				"������� ����� ������������, ������� �������� ������ �����:\n");

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
	else std::cout << "������� � ����� ������� �� ��������������� � �������!\n";
}
