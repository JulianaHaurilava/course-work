#include "Doctor.h"

Doctor::Doctor() : User::User()
{
	position = "_";
}

Doctor::Doctor(string encryptedPassword, bool role, FullName fullName,
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
	stringForFile += User::getStringForFile() + " " + fullName.getStringForFile() + " " +
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
