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
	stringForFile += User::getStringForFile() + " " + position;

	for (string login : vectorOfPatientLogins)
	{
		stringForFile += " " + login;
	}
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
		doctor.fullName >> doctor.dateOfBirth >> doctor.address >>
		doctor.position;

	for (string login : doctor.vectorOfPatientLogins)
	{
		in >> login;
	}
	return in;
}
