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

	Time();
	Time(int hour, int minute);

	friend std::ostream& operator<<(std::ostream& os, const Time& time);
	friend std::istream& operator>>(std::istream& in, Time& time);
};


