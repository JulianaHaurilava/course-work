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
	string getStringForLogin();
	void setCurrentDate();

	friend std::istream& operator >> (std::istream& in, Date& day);
	friend std::ostream& operator<<(std::ostream& os, const Date& day);

	friend bool operator<=(const Date& day_1, const Date& day_2);
	friend bool operator>=(const Date& day_1, const Date& day_2);
};

