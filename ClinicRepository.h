#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <iomanip>

#include "Checkups.h"

using std::string;

class ClinicRepository
{
	string serviceFileName = "service_file";
	std::map<string, double> allServices;

	void allServiceMapInFile();
	void allServiceMapOutOfFile();
	void addServiceInFile(string serviceName);

	friend class Administrator;

public:

	ClinicRepository();
	~ClinicRepository();

	void printTableOfServices();

	void addNewService(string name, double price);

	void deleteService(string name);

	double getPriceByName(string name);

	void editService(string name);
};

