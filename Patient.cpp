#include "Patient.h"

Patient::Patient()
{
	fullName = FullName();
	dateOfBirth = Date();
	address = Address();

	patientsDoctorLogin = "_";
	lastExtract = Extract();
}

Patient::Patient(FullName fullName, Date dateOfBirth, Address address, FullName doctorsName)
{
	this->fullName = fullName;
	this->dateOfBirth = dateOfBirth;
	this->address = address;
	patientsDoctorLogin = getLoginBuyName(doctorsName);
}


string Patient::getStringForFile()
{
	string stringForFile = "";
	stringForFile += Account::getStringForFile() + " " + fullName.getStringForFile() + " " +
		dateOfBirth.getStringForFile() + " " + address.getStringForFile() + " " + patientsDoctorLogin +
		lastExtract.getStringForFile();

	stringForFile += " @";
	for (const auto& serviceInfo : mapOfPaidServices)
	{
		stringForFile += " " + serviceInfo.first + " " + std::to_string(serviceInfo.second);
	}
	stringForFile += " @";
	return stringForFile;
}
