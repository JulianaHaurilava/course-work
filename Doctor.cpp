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


void Doctor::logInSystem(AccountRepository<Patient>& pr)
{
}

string Doctor::getStringForFile()
{
	return User::getStringForFile() + '\n' + position + '\n';
}


void Doctor::print()
{
	User::print();
	std::cout << "���������: " << position << std::endl;
}

FullName Doctor::getFullName()
{
	return fullName;
}

std::istream& operator >> (std::istream& in, Doctor& doctor)
{
	return in >> doctor.login >> doctor.encryptedPassword >> doctor.access >>
		doctor.fullName >> doctor.dateOfBirth >> doctor.address;
}
