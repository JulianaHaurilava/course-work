#pragma once
#include "Account.h"

#include "Doctor.h"
#include "Patient.h"

#include <vector>
#include <string>
#include <algorithm>
#include "Repository.h"

using std::string;

class Administrator :
	public Account
{
	string doctorFileName = "not_verified_doctors_file";
	string patientFileName = "not_verified_patient_file";

	std::vector<Doctor> vectorOfNotVerifiedDoctors;
	std::vector<Patient> vectorOfNotVerifiedPatients;

	int getIndexByLogin(string loginToFind);

	string getCorrectExistingLogin(std::istream& s, const char* message, Repository r);

	void allDoctorVectorInFile();
	void allPatientVectorInFile();

	void allDoctorVectorOutOfFile();
	void allPatientVectorOutOfFile();

public:
	Administrator();
	~Administrator();

	void logInSystem() override;

	/// <summary>
	/// ��������� ������ ������� � ������
	/// </summary>
	/// <param name="newPatient"> - </param>
	void addNewDoctor(Doctor newDoctor);

	/// <summary>
	/// ��������� ������ �������� � ������
	/// </summary>
	/// <param name="newPatient"> - </param>
	void addNewPatient(Patient newPatient);

	/// <summary>
	/// ������� ������� �� ������
	/// </summary>
	/// <param name="loginToDelete">- ����� ������������, �������� ����� �������</param>
	void deleteAccount(Repository r, string loginToDelete);

	void verifyAccount(Repository r, string login);

	
	
};

