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

	virtual bool editAccountInfo() = 0;

public:
	User();
	User(string encryptedPassword, int role,
		FullName fullName, Date dateOfBirth, Address address);

	bool getAccess();
	void enableAccess();
	virtual string getStringForFile();
	virtual void print();
	FullName getFullName();
};

