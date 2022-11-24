#pragma once

#include "Account.h"

#include "Doctor.h"
#include "Patient.h"
#include "Hash.h"

#include <vector>
#include <string>
#include <fstream>

//вся черновая работа (сортировка, файлы и тд)
class Repository
{
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
	/// Возвращает индекс аккаунта в векторе по логину. Если аккаунт не найден, возвращает -1.
	/// Если логин админа - -2.
	/// </summary>
	/// <param name="loginToFind">- логин аккаунта, индекс которого необходимо найти</param>
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
/// Добавляет нового пациента в вектор
/// </summary>
/// <param name="newPatient"> - </param>
	void addNewPatient(Patient newPatient);

	/// <summary>
/// Добавляет нового доктора в вектор
/// </summary>
/// <param name="newPatient"> - </param>
	void addNewDoctor(Doctor newDoctor);

	/// <summary>
/// Удаляет аккаунт по логину
/// </summary>
/// <param name="loginToDelete">- логин пользователя, которого нужно удалить</param>
	void deleteAccount(string loginToDelete);

	void verifyAccount(string loginToVerify);
};

template<typename T>
inline void Repository::allVectorInFile(std::vector<T> vector, string fileName)
{
	std::ofstream fout;
	fout.open(fileName, std::ios::trunc);

	if (!fout.is_open())
	{
		std::cout << "\nОшибка открытия файла!\n";
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
		std::cout << "\nОшибка открытия файла!\n";
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
