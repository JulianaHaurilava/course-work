#pragma once
#include "Account.h"
#include "FullName.h"
#include "Address.h"
#include "Date.h"
#include "Patient.h"

#include <vector>

using std::string;

class Doctor :
    public Account
{
    FullName fullName;
    Date dateOfBirth;
    Address address;
    string position;

    std::vector<Patient> vectorOfPatients;

public:

    Doctor();
    Doctor(FullName fullName, Date dateOfBirth, Address address, string position);

    string getStringForFile() override;
    void printAccountAsTable() override;
};

