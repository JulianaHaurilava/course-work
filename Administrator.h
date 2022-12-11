#pragma once
#include "Account.h"

#include "Doctor.h"
#include "Patient.h"
#include "ClinicRepository.h"

#include <vector>
#include <string>
#include <algorithm>

using std::string;

class Administrator :
	public Account
{
	

	void deactivateAccount(string loginToDeactivate, AccountRepository<Doctor>& dr,
		AccountRepository<Patient>& pr);

	void printAccountByLogin(string loginToPrint, AccountRepository<Doctor>& dr,
		AccountRepository<Patient>& pr);

	void workWithAccounts(AccountRepository<Doctor>& dr, AccountRepository<Doctor>& ndr,
		AccountRepository<Patient>& pr);

	void verifyAccount(string loginToVerify, AccountRepository<Doctor>& ndr,
		AccountRepository<Doctor>& dr);

	void workWithServices(ClinicRepository& cr);

	void editDoctorsPosition(string loginToEdit, AccountRepository<Doctor>& dr);

public:
	Administrator();
	~Administrator();

	void logInSystem(AccountRepository<Doctor>& dr, AccountRepository<Doctor>& ndr,
		AccountRepository<Patient>& pr, ClinicRepository& cr);
};

