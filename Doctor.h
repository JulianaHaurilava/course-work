#pragma once
#include "User.h"
#include "Patient.h"
#include "AccountRepository.h"

#include <vector>

using std::string;

class Doctor :
    public User
{
    string position;

    void workWithPatient(AccountRepository<Patient>& pr);
    

public:

    Doctor();
    Doctor(string encryptedPassword, int role, FullName fullName, Date dateOfBirth, Address address, string position);

    void logInSystem(AccountRepository<Patient>& pr);
    string getStringForFile() override;
    void print() override;
    bool editAccountInfo() override;
    friend std::istream& operator >> (std::istream& in, Doctor& doctor);
};

