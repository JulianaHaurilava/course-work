#pragma once
#include "User.h"
#include "FullName.h"
#include "Address.h"
#include "Date.h"
#include "Patient.h"
#include "Doctor.h"
#include "Extract.h"

#include <map>

using std::string;

class Patient :
    public User
{
    FullName fullName;
    Date dateOfBirth;
    Address address;

    string patientsDoctorLogin;

    std::map<string, double> mapOfPaidServices;

    Extract lastExtract;

public:
    Patient();
    Patient(FullName fullName, Date dateOfBirth, Address address, FullName doctorsName);

    string getStringForFile() override;
    void printAccountAsTable() override;
    FullName getFullName() override;
};

