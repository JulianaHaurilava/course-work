#include "Extract.h"

void Extract::addService(string serviceName, double price)
{
	mapOfUnpaidServices.insert(std::pair<string, double>(serviceName, price));
}

string Extract::getStringForFile()
{
	string stringForFile = "";
	stringForFile += std::to_string(totalPrice) + " " + "@" + recommendations + "@";

	for (const auto& [key, value] : mapOfUnpaidServices)
	{
		
	}
	return string();
}
