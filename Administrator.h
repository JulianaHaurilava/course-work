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
	string getCorrectExistingLogin(std::istream& s, const char* message, Repository r);



public:
	Administrator();
	~Administrator();

	void logInSystem() override;


	void workWithAccounts();
	void workWithServices();


};

