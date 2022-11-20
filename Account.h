#pragma once
#include <iostream>
#include <string>
#include "FullName.h"
#include "Date.h"
#include "Time.h"
#include "Address.h"
#include "Hash.h"
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
	bool getAccess();
	virtual void logInSystem();
	virtual string getStringForFile();

	void changeAccess();

	bool loginAndPasswordCorrect(string login, string password);
};

