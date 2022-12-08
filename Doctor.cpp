#include "Doctor.h"

Doctor::Doctor() : User::User()
{
	position = "_";
}

Doctor::Doctor(string encryptedPassword, int role, FullName fullName,
	Date dateOfBirth, Address address, string position):
	User::User(encryptedPassword, role, fullName, dateOfBirth, address)
{
	this->position = position;
}

void Doctor::workWithPatient(AccountRepository<Patient>& pr)
{
	std::cout << "������� ������ ��� ��������\n";

	FullName fullName;

	fullName.surname = getCorrectWordInput(std::cin, "�������: ");
	fullName.name = getCorrectWordInput(std::cin, "���: ");
	fullName.patronymic = getCorrectWordInput(std::cin, "��������: ");

	Patient* patientToWorkWith = pr.findAccountByFullName(fullName);

	if (patientToWorkWith->getLogin() == "_")
	{
		std::cout << "������� � ����� ������ �� ��������������� � �������!\n";
		delete patientToWorkWith;
		return;
	}

	std::cout << std::endl;
	patientToWorkWith->printInfoForDoctor();

	string diagnosis;
	string recommendations;

	std::cout << std::endl;
	std::cout << "������� ���������� � ������" << std::endl << std::endl;
	std::cout << "�������: ";
	getline(std::cin, diagnosis);

	std::cout << "������������: ";
	getline(std::cin, recommendations);

	patientToWorkWith->makeReport();

	patientToWorkWith->changeExtract(diagnosis, recommendations);
	pr.updateRepository();
}

bool Doctor::editAccountInfo()
{
	position = getCorrectStringInput(std::cin, "������� ����� ���������: ");
	return true;
}

void Doctor::logInSystem(AccountRepository<Patient>& pr)
{
	while (true)
	{
		std::cout << "��� �� ������ �������? �������� ��������������� �����.\n"
			"1 - ���������� ���������� �������;\n"
			"2 - �������� ���������� � ������;\n"
			"3 - �����.\n\n";

		int choice = getCorrectMenuInput(3);
		system("cls");
		switch (choice)
		{
		case 1:
			print();
			break;
		case 2:
			workWithPatient(pr);
			break;
		case 3:
			return;
		}
		endCase();
	}
}

string Doctor::getStringForFile()
{
	return User::getStringForFile() + '\n' + position + '\n';
}


void Doctor::print()
{
	User::print();
	std::cout << "���������: " << position << std::endl;
}

std::istream& operator >> (std::istream& in, Doctor& doctor)
{
	in >> doctor.login >> doctor.encryptedPassword >> doctor.access >>
		doctor.fullName >> doctor.dateOfBirth >> doctor.address;

	in.get();
	getline(in, doctor.position);

	return in;
}
