#pragma once
#include <stdexcept>

class InvalidPasswordExeption
	: public std::exception
{
public:
	InvalidPasswordExeption(const char* errorMessage) : std::exception(errorMessage)
	{

	}
};

