#pragma once
#include "User.h"
#include "FullName.h"
#include "Address.h"
#include "Date.h"
#include "Doctor.h"
#include "Extract.h"

#include <map>

using std::string;

class Patient :
    public User
{
    Extract lastExtract;

public:
    Patient();
    Patient(string encryptedPassword, int role, FullName fullName,
        Date dateOfBirth, Address address);

    void logInSystem();
    string getStringForFile() override;
    void print() override;
    FullName getFullName() override;

    friend std::istream& operator >> (std::istream& in, Patient& patient);
};

