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
    string doctorLogin;

    std::map<string, double> mapOfPaidServices;

    Extract lastExtract;

public:
    Patient();
    Patient(string encryptedPassword, bool role, FullName fullName,
        Date dateOfBirth, Address address, string doctorLogin);

    void logInSystem() override;
    string getStringForFile() override;
    void printAccountAsTable() override;
    FullName getFullName() override;
};

