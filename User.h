#pragma once
#include "Account.h"

#include "ClinicRepository.h"
#include <iomanip>

class User :
    public Account
{
protected:
	FullName fullName;
	Date dateOfBirth;
	Address address;
public:
	User();
	User(string encryptedPassword, int role,
		FullName fullName, Date dateOfBirth, Address address);

	void enableAccess();
	virtual string getStringForFile();
	virtual void print();
	virtual FullName getFullName() = 0;
};

