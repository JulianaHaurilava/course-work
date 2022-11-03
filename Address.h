#pragma once
#include <iostream>
#include <string>
using std::string;

struct Address
{
	string city;
	string street;
	int houseNumber;
	int flatNumber;

	Address();

	string getStringForFile();
};

