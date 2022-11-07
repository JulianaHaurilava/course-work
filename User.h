#pragma once
#include "Account.h"
class User :
    public Account
{
public:
	virtual string getStringForFile();
	virtual void printAccountAsTable() = 0;
	virtual FullName getFullName() = 0;
};

