#pragma once
#include <iostream>
#include <time.h>
#include <string>
using std::string;

struct Date
{
	int day;
	int month;
	int year;

	Date();
	Date(int day, int month, int year);

	string getStringForFile();
};

