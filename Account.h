#pragma once

#include "FullName.h"
#include "Date.h"
#include "Time.h"
#include "Address.h"
#include "Hash.h"
#include "AccountRepository.h"

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

	virtual string getStringForFile();

public:

	Account();
	Account(string encryptedPassword, int role);

	string getLogin();
	string getEncryptedPassword();
	bool checkLoginAndPassword(string login, string password);
};

