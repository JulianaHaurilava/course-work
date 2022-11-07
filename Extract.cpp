#include "Extract.h"

Extract::Extract()
{
	diagnosis = "_";
	totalPrice = 0;
	recommendations = "_";
}

void Extract::addService(string serviceName, double price)
{
	mapOfUnpaidServices.insert(std::pair<string, double>(serviceName, price));
}

string Extract::getStringForFile()
{
	string stringForFile = "";
	stringForFile += diagnosis + " " + std::to_string(totalPrice) + " " + "@" + recommendations + "@";

	stringForFile += " @";
	for (const auto& serviceInfo : mapOfUnpaidServices)
	{
		stringForFile += " " + serviceInfo.first + " " + std::to_string(serviceInfo.second);
	}
	stringForFile += " @";
	return stringForFile;
}

void Extract::print()
{
}
