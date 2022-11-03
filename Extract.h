#pragma once
#include <iostream>
#include <string>
#include <map>

using std::string;

class Extract //or struct?????
{
	string diagnosis;

	std::map<string, double> mapOfUnpaidServices;
	double totalPrice;

	string recommendations;
public:

	Extract();

	void addService(string serviceName, double price);
	string getStringForFile();
	void print();
};

