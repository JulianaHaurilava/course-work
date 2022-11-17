#include "Address.h"

std::ostream& operator<<(std::ostream& os, const Address& address)
{
    os << "�. " << address.city << " ��. " << address.street << " �. " << address.houseNumber;
	if (address.flatNumber != 0)
	{
		os << " ��. " << address.flatNumber;
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

std::istream& operator>>(std::istream& in, Address& address)
{
	in >> address.city >> address.street >> address.houseNumber >>
		address.flatNumber;
	return in;
}
