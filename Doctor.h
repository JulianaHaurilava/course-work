#pragma once
#include "User.h"
#include "FullName.h"
#include "Address.h"
#include "Date.h"
#include "Patient.h"

#include <vector>

using std::string;

class Doctor :
    public User
{
    FullName fullName;
    Date dateOfBirth;
    Address address;
    string position;

    std::vector<string> vectorOfPatientLogins;

public:

    Doctor();
    Doctor(FullName fullName, Date dateOfBirth, Address address, string position);

    string getStringForFile() override;
    void printAccountAsTable() override;
    FullName getFullName() override;
};

