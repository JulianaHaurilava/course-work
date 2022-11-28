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
	std::cout << "Логин: " << login << std::endl;
	std::cout << "Ф.И.О: " << fullName << std::endl;
	std::cout << "Дата рождения: " << dateOfBirth << std::endl;
	std::cout << "Адрес: " << address << std::endl;
}


