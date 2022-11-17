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
	stringForFile += User::getStringForFile() + " " + doctorLogin +
		lastExtract.getStringForFile();
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

std::istream& operator >> (std::istream& in, Patient& patient)
{
	return in >> patient.login >> patient.encryptedPassword >> patient.access >>
		patient.fullName >> patient.dateOfBirth >> patient.address >>
		patient.doctorLogin >> patient.lastExtract;
}
