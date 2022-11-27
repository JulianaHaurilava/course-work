#pragma once
#include "User.h"
#include "Extract.h"

using std::string;

class Patient :
    public User
{
    Extract lastExtract;

public:
    Patient();
    Patient(string encryptedPassword, int role, FullName fullName,
        Date dateOfBirth, Address address);

    void logInSystem(ClinicRepository& cr);
    string getStringForFile() override;
    void print() override;
    FullName getFullName() override;

    friend std::istream& operator >> (std::istream& in, Patient& patient);
};

