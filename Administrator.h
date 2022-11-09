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
	std::vector<Doctor> vectorOfNotVerifiedDoctors;
	std::vector<Patient> vectorOfNotVerifiedPatients;


	string getCorrectExistingLogin(std::istream& s, const char* message, Repository r);

public:
	Administrator();

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

	int getIndexByLogin(string loginToFind);
	
};

