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
			"5 - ���������� ������;\n"
			"6 - �����.\n\n";

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
			break;
		case 2:
			std::cout << "������� ���� �������� (��.��.����)\n";
			dateOfBirth = getCorrectDateOfBirth(std::cin, 2);
			break;
		case 3:
			std::cout << "������� ����� ����������\n";
			address.city = getCorrectWordInput(std::cin, "�����: ");
			address.street = getCorrectStringInput(std::cin, "�����: ");
			address.houseNumber = getCorrectPositiveInteger(std::cin, "����� ����: ");
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
	std::cout << "��� ����, ����� ����� ������� ������ ������.\n";
	while (true)
	{
		std::cout << "������� �������� ������, ������� ������ ����������.";
	}
}

std::istream& operator >> (std::istream& in, Patient& patient)
{
	return in >> patient.login >> patient.encryptedPassword >> patient.access >>
		patient.fullName >> patient.dateOfBirth >> patient.address >>
		patient.lastExtract;
}
