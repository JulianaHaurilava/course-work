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

	friend std::istream& operator>>(std::istream& in, Address& day);
	friend std::ostream& operator<<(std::ostream& os, const Address& address);
};

