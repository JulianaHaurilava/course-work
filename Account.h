#pragma once
#include <iostream>
#include <string>
#include "FullName.h"
#include "Date.h"
#include "Time.h"
using std::string;

//abstract
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
};

