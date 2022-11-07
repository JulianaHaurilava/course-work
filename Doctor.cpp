#include "Doctor.h"

Doctor::Doctor()
{
	fullName = FullName();
	dateOfBirth = Date();
	address = Address();
	position = "_";
}

Doctor::Doctor(FullName fullName, Date dateOfBirth, Address address, string position)
{
	this->fullName = fullName;
	this->dateOfBirth = dateOfBirth;
	this->address = address;
	this->position = position;
}

string Doctor::getStringForFile()
{
	string stringForFile = "";
	stringForFile += Account::getStringForFile() + " " + fullName.getStringForFile() + " " +
		dateOfBirth.getStringForFile() + " " + address.getStringForFile() + " " + position;

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
