#pragma once

#include "FullName.h"
#include "Date.h"
#include "Time.h"
#include "Address.h"
#include "Hash.h"

#include <iostream>
#include <string>
using std::string;

class Account
{
private:
	string generateLogin(int role);
protected:
	string login;
	string encryptedPassword;
	bool access;

public:

	Account();
	Account(string encryptedPassword, int role);

	string getLogin();
	string getEncryptedPassword();

	virtual string getStringForFile();

	bool loginAndPasswordCorrect(string login, string password);
};

