#pragma once
#include "Account.h"

#include "Doctor.h"
#include "Patient.h"
#include "ClinicRepository.h"
#include "AccountRepository.h"
#include "Checkups.h"

#include <vector>
#include <string>
#include <algorithm>


using std::string;

class Administrator :
	public Account
{
	string getCorrectLogin(std::istream& s, const char* message);

public:
	Administrator();
	~Administrator();

	void logInSystem(AccountRepository<Doctor>& dr, AccountRepository<Doctor>& ndr,
		AccountRepository<Patient>& pr, ClinicRepository& cr);


	void workWithAccounts(AccountRepository<Doctor>& dr, AccountRepository<Doctor>& ndr,
		AccountRepository<Patient>& pr);

	void verifyAccount(string loginToVerify, AccountRepository<Doctor>& ndr,
		AccountRepository<Doctor>& dr);
	void deactivateAccount(string loginToDeactivate, AccountRepository<Doctor>& dr,
		AccountRepository<Patient>& pr);
	void printAccountByLogin(string loginToFind, AccountRepository<Doctor>& dr,
		AccountRepository<Patient>& pr);

	void workWithServices(ClinicRepository& cr);

};

