#include "Extract.h"

Extract::Extract()
{
	diagnosis = "_";
	totalPrice = 0;
	recommendations = "_";
}

string Extract::getStringForFile()
{
	string stringForFile = "";
	stringForFile += diagnosis + " " + std::to_string(totalPrice) + " \n" + recommendations + "\n";
	return stringForFile;
}

void Extract::print()
{
}

std::istream& operator >> (std::istream& in, Extract& extract)
{
	in >> extract.diagnosis >> extract.totalPrice;
	string emptyString;
	getline(in, emptyString);

	getline(in, extract.recommendations);

	return in;
}
