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

bool User::getAccess()
{
	return access;
}

void User::enableAccess()
{
	access = !access;
}

string User::getStringForFile()
{

    return Account::getStringForFile() + " " + fullName.getStringForFile() + " " +
		dateOfBirth.getStringForFile() + " " + address.getStringForFile();

}

void User::print()
{
	std::cout << "�����: " << login << std::endl;
	std::cout << "�.�.�: " << fullName << std::endl;
	std::cout << "���� ��������: " << dateOfBirth << std::endl;
	std::cout << "�����: " << address << std::endl;
}

FullName User::getFullName()
{
	return fullName;
}


