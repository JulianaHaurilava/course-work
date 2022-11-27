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
}

string Patient::getStringForFile()
{
	return  User::getStringForFile() + " " + lastExtract.getStringForFile();
}

void Patient::print()
{
	User::print();
}

FullName Patient::getFullName()
{
	return fullName;
}

std::istream& operator >> (std::istream& in, Patient& patient)
{
	return in >> patient.login >> patient.encryptedPassword >> patient.access >>
		patient.fullName >> patient.dateOfBirth >> patient.address >>
		patient.lastExtract;
}
