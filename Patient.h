#pragma once
#include "Account.h"
#include "FullName.h"
#include "Address.h"
#include "Date.h"
#include "Patient.h"

#include <map>

using std::string;

class Patient :
    public Account
{
    FullName fullName;
    Date dateOfBirth;
    Address address;

    Doctor patientsDoctor;

    std::map<string, double> mapOfPaidServices;
};

