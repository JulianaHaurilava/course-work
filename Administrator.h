#pragma once
#include "Account.h"

#include "Doctor.h"
#include "Patient.h"
#include "Repository.h"
#include "Checkups.h"

#include <vector>
#include <string>
#include <algorithm>


using std::string;

class Administrator :
	public Account
{
	string getCorrectLogin(std::istream& s, const char* message, Repository& r);

public:
	Administrator();
	~Administrator();

	void logInSystem(Repository &r);


	void workWithAccounts(Repository& r);

	void verifyAccount(string loginToVerify, Repository& r);
	void deactivateAccount(string loginToDeactivate, Repository& r);
	void printAccountByLogin(string loginToFind, Repository& r);

	void workWithServices(Repository& r);

	
};

