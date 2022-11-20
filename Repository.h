#pragma once

#include "Account.h"

#include "Doctor.h"
#include "Patient.h"
#include "Hash.h"

#include <vector>
#include <string>
#include <fstream>

//��� �������� ������ (����������, ����� � ��)
class Repository
{
	string doctorFileName = "doctors_file";
	string patientFileName = "patient_file";
	string serviceFileName = "service_file";

	std::vector<Doctor> vectorOfAllDoctors;
	std::vector<Patient> vectorOfAllPatients;

	std::map<string, double> allServices;

	void allDoctorVectorInFile();
	void allPatientVectorInFile();
	void allServiceMapInFile();

	void allDoctorVectorOutOfFile();
	void allPatientVectorOutOfFile();
	void allServiceMapOutOfFile();

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

	/// <summary>
/// ��������� ������ �������� � ������
/// </summary>
/// <param name="newPatient"> - </param>
	void addNewPatient(Patient newPatient);
};

