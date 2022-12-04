#pragma once
#include "User.h"
#include "Extract.h"

using std::string;

class Patient :
    public User
{
    Extract lastExtract;

    std::map<string, double> mapOfUnpaidServices;
    double totalPrice;

    void editAccountInfo();
    void buyService(ClinicRepository cr);
    void printUnpaidServices();

public:
    Patient();
    Patient(string encryptedPassword, int role, FullName fullName,
        Date dateOfBirth, Address address);

    void logInSystem(ClinicRepository& cr);

    string getStringForFile() override;
    void print() override;
    void printInfoForDoctor();
    void changeExtract(string newDiagnosis, string newRecommendation);

    friend std::istream& operator >> (std::istream& in, Patient& patient);
};

