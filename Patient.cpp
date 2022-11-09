#include "Patient.h"

Patient::Patient() : User::User()
{
	doctorLogin = "_";
	lastExtract = Extract();
}

Patient::Patient(string encryptedPassword, bool role, FullName fullName,
	Date dateOfBirth, Address address, string doctorLogin):
	User::User(encryptedPassword, role, fullName, dateOfBirth, address)
{
	this->doctorLogin = doctorLogin;
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
