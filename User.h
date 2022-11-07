#pragma once
#include "Account.h"
class User :
    public Account
{
protected:
	FullName fullName;
	Date dateOfBirth;
	Address address;
public:
	User();
	User(string encryptedPassword, bool role,
		FullName fullName, Date dateOfBirth, Address address);

	virtual string getStringForFile();
	virtual void printAccountAsTable() = 0;
	virtual FullName getFullName() = 0;
};

