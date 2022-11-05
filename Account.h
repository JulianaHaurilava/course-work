#pragma once
#include <iostream>
#include <string>
using std::string;

//abstract
class Account
{
protected:
	string login;
	string encryptedPassword;
	int role;
	bool access;

public:
	Account(); // здесь генерация логина

	virtual string getStringForFile();
	virtual void printAccountAsTable() = 0;
	void changeAccess();
	string getLogin();
};

