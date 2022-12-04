#pragma once
#include <iostream>
#include <string>
#include <map>

using std::string;

class Extract
{
	string diagnosis;

	std::map<string, double> mapOfPaidServices;

	double totalPrice;

	string recommendations;
public:

	Extract();
	string getStringForFile();
	void print();
	void printExtractForDoctor();

	void setDiagnosis(string diagnosis);
	void setRecommendations(string recommendations);
	void setMap(std::map<string, double> mapOfPaidServices);

	friend std::istream& operator >> (std::istream& in, Extract& extract);
};

