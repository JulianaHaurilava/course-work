#pragma once
#include "Account.h"

#include "Doctor.h"
#include "Patient.h"

#include <vector>
#include <string>

using std::string;
class Administrator :
	public Account
{
	std::vector<Doctor> vectorOfAllDoctors;
	std::vector<Doctor> vectorOfAllPatients;

public:

	void addNewDoctor(Doctor newDoctor);
	void addNewPatient(Doctor newPatient);

	void deleteAccount(string loginToDelete);

	int getIndexByLogin(string loginToFind);

};

