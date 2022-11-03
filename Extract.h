#pragma once
#include <iostream>
#include <string>
#include <map>

using std::string;

class Extract //or struct?????
{
	std::map<string, double> mapOfUnpaidServices;

	double totalPrice;
	string recommendations;

public:

	void addService(string serviceName, double price);
	string getStringForFile();
	void print();
};

