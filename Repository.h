#pragma once

#include "Account.h"

#include "Doctor.h"
#include "Patient.h"
#include "Hash.h"

#include <vector>
#include <string>
#include <conio.h>
#include <fstream>

//��� �������� ������ (����������, ����� � ��)
class Repository
{
	string doctorFileName = "doctors_file";
	string patientFileName = "patient_file";

	std::vector<Doctor> vectorOfAllDoctors;
	std::vector<Patient> vectorOfAllPatients;

	void allDoctorVectorInFile();
	void allPatientVectorInFile();

	void allDoctorVectorOutOfFile();
	void allPatientVectorOutOfFile();


	/// <summary>
	/// ���������� ������ �������� � ������� �� ������. ���� ������� �� ������, ���������� -1.
	/// ���� ����� ������ - -2.
	/// </summary>
	/// <param name="loginToFind">- ����� ��������, ������ �������� ���������� �����</param>
	/// <returns></returns>
	int getIndexByLogin(string loginToFind);
	friend class Administrator;

public:

	Repository();
	~Repository();

	Doctor findDoctorByLogin(string login);
	Patient findPatientByLogin(string login);
};

