#pragma once
#include <iostream>
#include <string>
#include <map>

using std::string;

class Extract
{
	string diagnosis;

	double totalPrice;

	string recommendations;
public:

	Extract();
	string getStringForFile();
	void print();

	friend std::istream& operator >> (std::istream& in, Extract& extract);
};

