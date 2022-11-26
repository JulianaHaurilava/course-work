#pragma once

#include "Account.h"

#include "Doctor.h"
#include "Patient.h"
#include "Hash.h"

#include <vector>
#include <string>
#include <fstream>
#include "Checkups.h"

//��� �������� ������ (����������, ����� � ��)
class Repository
{
	string clinicName = "������ ������� � ����";

	string doctorFileName = "doctors_file";
	string patientFileName = "patient_file";
	string serviceFileName = "service_file";
	string doctorNonVerifiedFileName = "not_verified_doctors_file";

	std::vector<Doctor> vectorOfNotVerifiedDoctors;
	std::vector<Doctor> vectorOfAllDoctors;
	std::vector<Patient> vectorOfAllPatients;

	std::map<string, double> allServices;

	void allServiceMapInFile();

	template <typename T>
	void allVectorInFile(std::vector<T> vector, string fileName);

	template <typename T>
	void allVectorOutOfFile(std::vector<T> &vector, string fileName);
	
	void allServiceMapOutOfFile();

	/// <summary>
	/// ���������� ������ �������� � ������� �� ������. ���� ������� �� ������, ���������� -1.
	/// ���� ����� ������ - -2.
	/// </summary>
	/// <param name="loginToFind">- ����� ��������, ������ �������� ���������� �����</param>
	/// <returns></returns>
	int getNonVerifiedIndexByLogin(string loginToFind);

	int getIndexByLogin(string loginToFind);

	friend class Administrator;

public:

	Repository();
	~Repository();

	Doctor findDoctorByLogin(string login);
	Patient findPatientByLogin(string login);
	Doctor findNotVerifiedDoctorByLogin(string login);

	/// <summary>
/// ��������� ������ �������� � ������
/// </summary>
/// <param name="newPatient"> - </param>
	void addNewPatient(Patient newPatient);

	/// <summary>
/// ��������� ������ ������� � ������
/// </summary>
/// <param name="newPatient"> - </param>
	void addNewDoctor(Doctor newDoctor);

	/// <summary>
/// ������� ������� �� ������
/// </summary>
/// <param name="loginToDelete">- ����� ������������, �������� ����� �������</param>
	void deleteAccount(string loginToDelete);

	template <typename T>
	void printAllAccounts(std::vector<T> vector);


	void printTableOfServices();

	void addNewService(string name, double price);

	void deleteService(string name);

	double getPriceByName(string name);

	void editService(string name);
};

template<typename T>
inline void Repository::allVectorInFile(std::vector<T> vector, string fileName)
{
	std::ofstream fout;
	fout.open(fileName, std::ios::trunc);

	if (!fout.is_open())
	{
		std::cout << "\n������ �������� �����!\n";
		return;
	}

	for (T info : vector)
	{
		fout << info.getStringForFile();
	}

	fout.close();
}

template<typename T>
inline void Repository::allVectorOutOfFile(std::vector<T> &vector, string fileName)
{
	std::fstream fs;
	fs.open(fileName, std::ios::in | std::fstream::app);

	if (!fs.is_open())
	{
		std::cout << "\n������ �������� �����!\n";
		return;
	}

	do
	{
		T info = T();
		fs >> info;
		vector.push_back(info);

	} while (!fs.eof());

	if (vector.back().getLogin() == "_")
	{
		vector.pop_back();
	}
	fs.close();
}

template<typename T>
inline void Repository::printAllAccounts(std::vector<T> vector)
{
	for (T vectorItem : vector)
	{
		vectorItem.print();
		std::cout << std::endl;
	}
}
