#include "Date.h"

Date::Date()
{
	day = 0;
	month = 0;
	year = 1000;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

string Date::getStringForFile()
{
	return std::to_string(day) + " " + std::to_string(month) + " " + std::to_string(year);
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	return os << date.day << "." << date.month << "." << date.year;
}
