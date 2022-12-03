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

	friend bool operator==(const FullName& fullName_1, const FullName& fullName_2);
	friend bool operator!=(const FullName& fullName_1, const FullName& fullName_2);
};

