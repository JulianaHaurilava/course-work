#pragma once
#include <iostream>
#include <string>
using std::string;

//abstract
class Account
{
	string  login;
	string encryptedPassword;
	int role;
	bool access;

public:
	virtual string getStringForFile();
	virtual void printAccountAsTable() = 0;
};

