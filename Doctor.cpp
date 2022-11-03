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

	for (Patient patient : vectorOfPatients)
	{
		stringForFile += " " + patient.getStringForFile();
	}
	return stringForFile;
}

void Doctor::printAccountAsTable()
{
}
