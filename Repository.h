#pragma once

#include "Account.h"

#include "Doctor.h"
#include "Patient.h"
#include "Hash.h"

#include <vector>
#include <string>
#include <conio.h>

//��� �������� ������ (����������, ����� � ��)
class Repository
{
	std::vector<Doctor> vectorOfAllDoctors;
	std::vector<Patient> vectorOfAllPatients;

	/*bool sortAccountsBySurname(const Account& account_1, const Account& account_2);

	void sortDoctorsBySurname(std::vector <Doctor>& employees);
	void sortPatientsBySurname(std::vector <Patient>& employees);*/

	/// <summary>
	/// ���������� ������ �������� � ������� �� ������. ���� ������� �� ������, ���������� -1.
	/// ���� ����� ������ - -2.
	/// </summary>
	/// <param name="loginToFind">- ����� ��������, ������ �������� ���������� �����</param>
	/// <returns></returns>
	int getIndexByLogin(string loginToFind);
	friend class Administrator;

public:
	Doctor findDoctorByLogin(string login);
	Patient findPatientByLogin(string login);
};

