#include "Extract.h"

Extract::Extract()
{
	diagnosis = "_";
	totalPrice = 0;
	recommendations = "_";
}

string Extract::getStringForFile()
{
	return diagnosis + '\n' + std::to_string(totalPrice) + " " + recommendations + '\n';
}

void Extract::print()
{
}

std::istream& operator >> (std::istream& in, Extract& extract)
{
	getline(in, extract.diagnosis);
	in.get();
	in >> extract.totalPrice;
	getline(in, extract.recommendations);

	return in;
}
