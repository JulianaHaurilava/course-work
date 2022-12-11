#include "Administrator.h"



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
		std::cout << "��� �� ������ �������? �������� ��������������� �����.\n"
			"1 - ������ � �������� ������;\n"
			"2 - ������ � ����������;\n"
			"3 - �����.\n\n";

		int choice = chps::getCorrectMenuInput(3);
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
	}
}

void Administrator::workWithAccounts(AccountRepository<Doctor>& dr, AccountRepository<Doctor>& ndr,
	AccountRepository<Patient>& pr)
{
	while (true)
	{
		std::cout << "��� �� ������ �������? �������� ��������������� �����.\n"
			"1 - ����������� ���������� ��� ���� ������;\n"
			"2 - ����������� ���������� ��� ���� ���������;\n"
			"3 - ����������� ���������� ��� ���� ������������������ ���������;\n"
			"4 - �������������� �������;\n"
			"5 - �������������� �������;\n"
			"6 - ����� ������� �� ������;\n"
			"7 - ������������� ��������� ����������;\n"
			"8 - �����.\n\n";

		int choice = chps::getCorrectMenuInput(8);
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
			std::cout << "��� ����, ����� ����� ������� ������ ������.\n\n";
			string loginToVerify = chps::getCorrectLogin(std::cin, 
				"������� ����� ������������, �������� ������ ��������������:\n");

			if (loginToVerify == "") break;

			verifyAccount(loginToVerify, ndr, dr);
			break;
		}
		case 5:
		{
			std::cout << "��� ����, ����� ����� ������� ������ ������.\n\n";
			string loginToDeactivate = chps::getCorrectLogin(std::cin,
				"������� ����� ������������, ������� �������� ������ ��������������:\n");

			if (loginToDeactivate == "") break;

			deactivateAccount(loginToDeactivate, dr, pr);
			break;
		}
		case 6:
		{
			std::cout << "��� ����, ����� ����� ������� ������ ������.\n\n";
			string loginToPrint = chps::getCorrectLogin(std::cin,
				"������� ����� ������������, ������� �������� ������ �����:\n");

			if (loginToPrint == "") break;

			printAccountByLogin(loginToPrint, dr, pr);
			break;
		}
		case 7:
		{
			std::cout << "��� ����, ����� ����� ������� ������ ������.\n\n";
			string loginToEdit = chps::getCorrectLogin(std::cin,
				"������� ����� ����������, ��� ��������� ������ �������������:\n");

			if (loginToEdit == "") break;
			editDoctorsPosition(loginToEdit, dr);
			break;
		}
		case 8:
			return;
		}
		chps::endCase();
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

		int choice = chps::getCorrectMenuInput(6);
		system("cls");
		switch (choice)
		{
		case 1:
			cr.printTableOfServices();
			break;
		case 2:
		{
			std::cout << "������� ���������� � ����� ������\n";
			string name = chps::getCorrectStringInput(std::cin, "�������� ������: ");
			double price = chps::getCorrectPositiveDouble(std::cin, "����: ");
			cr.addNewService(name, price);
			break;
		}
		case 3:
		{
			std::cout << "������� �������� ������, ������� ������ �������\n";
			string name = chps::getCorrectStringInput(std::cin, "�������� ������: ");
			cr.deleteService(name);
			break;
		}
		case 4:
		{
			std::cout << "������� �������� ������, ���������� � ������� ������ �������������\n";
			string name = chps::getCorrectStringInput(std::cin, "�������� ������: ");
			cr.editService(name);
			break;
		}
		case 5:
		{
			std::cout << "������� �������� ������, ���� ������� ������ ������\n";
			string name = chps::getCorrectStringInput(std::cin, "�������� ������: ");
			double foundPrice = cr.getPriceByName(name);
			if (foundPrice != 0)
			{
				std::cout << "����: " << foundPrice << " BYN" << std::endl;
			}
			else std::cout << "������ �� �������!\n";
			break;
		}
		case 6:
			return;
		}
		chps::endCase();
	}
}

void Administrator::editDoctorsPosition(string loginToEdit, AccountRepository<Doctor>& dr)
{
	Doctor* doctorToEdit = dr.findAccountByLogin(loginToEdit);
	if (doctorToEdit->getAccess())
	{
		doctorToEdit->editAccountInfo();
		dr.updateRepository();
		std::cout << "������ ������� ��������!\n";
		return;
	}
	std::cout << "������������ � ����� ������ �� ��������������� � �������!\n";
}

void Administrator::deactivateAccount(string loginToDeactivate, AccountRepository<Doctor>& dr,
	AccountRepository<Patient>& pr)
{
	int role = stoi(loginToDeactivate.substr(0, 2));

	switch (role)
	{
	case 2:
		dr.deleteAccount(loginToDeactivate);
		std::cout << "������� �������������!\n";
		break;
	case 3:
		pr.deleteAccount(loginToDeactivate);
		std::cout << "������� �������������!\n";
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
		std::cout << "������� �������������!\n";
	}
	else std::cout << "������� � ����� ������� �� ��������������� � �������!\n";
}
