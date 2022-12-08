#pragma once
#include "User.h"
#include "Extract.h"
#include "AccountRepository.h"

using std::string;

const string REPORT_FILE_NAME = "report.txt";

class Patient :
    public User
{
    Extract lastExtract;

    std::map<string, double> mapOfUnpaidServices;
    double totalPrice;

    bool editAccountInfo();
    bool buyService(ClinicRepository cr);
    void printUnpaidServices();

public:
    Patient();
    Patient(string encryptedPassword, int role, FullName fullName,
        Date dateOfBirth, Address address);

    void logInSystem(ClinicRepository& cr, AccountRepository<Patient>& pr);

    string getStringForFile() override;
    void print() override;
    void printInfoForDoctor();
    void changeExtract(string newDiagnosis, string newRecommendation);
    void makeReport();
    void printUnpaidServicesForDoctor();

    friend std::istream& operator >> (std::istream& in, Patient& patient);
};

