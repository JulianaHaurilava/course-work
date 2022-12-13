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
	string stringForLogin = "";
	day < 10 ? stringForLogin += "0" + std::to_string(day) : stringForLogin += std::to_string(day);
	month < 10 ? stringForLogin += "0" + std::to_string(month) : stringForLogin += std::to_string(month);

	return stringForLogin + std::to_string(year);
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
	date.day < 10 ? os << "0" << date.day << "." : os << date.day << ".";
	date.month < 10 ? os << "0" << date.month << "." : os << date.month << ".";

	return os << date.year;
}

bool operator<=(const Date& day_1, const Date& day_2)
{
	return day_1.day <= day_2.day && day_1.month <= day_2.month &&
		day_1.year <= day_2.year;
}

bool operator>=(const Date& day_1, const Date& day_2)
{
	return day_1.day >= day_2.day&& day_1.month >= day_2.month&&
		day_1.year >= day_2.year;
}

std::istream& operator>>(std::istream& in, Date& day)
{
	in >> day.day >> day.month >> day.year;
	return in;
}
