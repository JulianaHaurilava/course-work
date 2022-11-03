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

};

