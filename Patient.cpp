#include "Patient.h"

Patient::Patient() : User::User()
{
	doctorLogin = "_";
	lastExtract = Extract();
}

Patient::Patient(string encryptedPassword, int role, FullName fullName,
	Date dateOfBirth, Address address):
	User::User(encryptedPassword, role, fullName, dateOfBirth, address)
{
}

void Patient::logInSystem()
{
}

string Patient::getStringForFile()
{
	string stringForFile = "";
	stringForFile += User::getStringForFile() + " " + fullName.getStringForFile() + " " +
		dateOfBirth.getStringForFile() + " " + address.getStringForFile() + " " + doctorLogin +
		lastExtract.getStringForFile();

	stringForFile += " @";
	for (const auto& serviceInfo : mapOfPaidServices)
	{
		stringForFile += " " + serviceInfo.first + " " + std::to_string(serviceInfo.second);
	}
	stringForFile += " @";
	return stringForFile;
}

void Patient::printAccountAsTable()
{
}

FullName Patient::getFullName()
{
	return fullName;
}

void Patient::setDoctorLogin(string doctorLogin)
{
	this->doctorLogin = doctorLogin;
}
