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
    string position;

    std::vector<string> vectorOfPatientLogins;

public:

    Doctor();
    Doctor(string encryptedPassword, int role, FullName fullName, Date dateOfBirth, Address address, string position);

    void logInSystem();
    string getStringForFile() override;
    void print() override;
    FullName getFullName() override;

    friend std::istream& operator >> (std::istream& in, Doctor& doctor);
};

