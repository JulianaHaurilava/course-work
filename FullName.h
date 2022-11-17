#pragma once
#include <iostream>
using std::string;

struct FullName
{
	string name;
	string surname;
	string patronymic;

	FullName();

	string getStringForFile();

	friend std::istream& operator>>(std::istream& in, FullName& fullName);
	friend std::ostream& operator<<(std::ostream& os, const FullName& fullName);

};

