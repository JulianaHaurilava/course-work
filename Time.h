#pragma once

#include <iostream>
#include <time.h>
#include <string>
using std::string;

struct Time
{
	int hour;
	int minute;
	int second;

	string getStringForFile();
	string getStringForLogin();
	void setCurrentTime();
};


