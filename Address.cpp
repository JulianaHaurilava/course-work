#include "Address.h"

std::ostream& operator<<(std::ostream& os, const Address& address)
{
    os << "г. " << address.city << " ул. " << address.street << " д. " << address.houseNumber;
	if (address.flatNumber != 0)
	{
		os << " кв. " << address.flatNumber;
	}
	return os;
}

Address::Address()
{
	city = "_";
	street = "_";
	houseNumber = 0;
	flatNumber = 0;
}

string Address::getStringForFile()
{
	return city + " " + street + " " + std::to_string(houseNumber) + " " + std::to_string(flatNumber);
}
