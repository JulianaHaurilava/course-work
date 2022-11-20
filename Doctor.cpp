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

void Doctor::logInSystem()
{
}

string Doctor::getStringForFile()
{
	string stringForFile = "";
	stringForFile += User::getStringForFile() + '\n' + position + '\n';

	for (string login : vectorOfPatientLogins)
	{
		stringForFile += login + " ";
	}
	stringForFile.back() = '\n';
	return stringForFile;
}

void Doctor::printAccountAsTable()
{
}

FullName Doctor::getFullName()
{
	return fullName;
}

std::istream& operator >> (std::istream& in, Doctor& doctor)
{
	in >> doctor.login >> doctor.encryptedPassword >> doctor.access >>
		doctor.fullName >> doctor.dateOfBirth >> doctor.address;

	in.get();
	getline(in, doctor.position);

	int index = 0;

	char next_c = in.get();

	while (in.peek() == 3)
	{
		in.seekg(-2, in.cur);
		in >> doctor.vectorOfPatientLogins[index++];
	}

	if (in.peek() == '2') in.seekg(-2, in.cur);
	else in.get();

	return in;
}
