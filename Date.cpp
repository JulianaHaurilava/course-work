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

string Date::getStringForLogin()
{
	return std::to_string(day) + std::to_string(month) + std::to_string(year);
}

void Date::setCurrentDate()
{
	struct tm localtime;
	time_t now = time(NULL);
	localtime_s(&localtime, &now);
	day = localtime.tm_mday;
	month = 1 + localtime.tm_mon;
	year = 1900 + localtime.tm_year;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	return os << date.day << "." << date.month << "." << date.year;
}
