#include "User.h"

User::User() : Account()
{
	fullName = FullName();
	dateOfBirth = Date();
	address = Address();
}

User::User(string encryptedPassword, int role,
	FullName fullName, Date dateOfBirth, Address address):Account(encryptedPassword, role)
{
	this->fullName = fullName;
	this->dateOfBirth = dateOfBirth;
	this->address = address;
}

string User::getStringForFile()
{

    return login + " " + encryptedPassword + " " + std::to_string(access) + " " + fullName.getStringForFile() + " " +
		dateOfBirth.getStringForFile() + " " + address.getStringForFile();

}
