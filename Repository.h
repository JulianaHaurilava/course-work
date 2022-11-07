#pragma once

#include "Account.h"

#include "Doctor.h"
#include "Patient.h"
#include "Administrator.h"
#include "Hash.h"

#include <vector>
#include <string>
#include <conio.h>

//вся черновая работа (сортировка, файлы и тд)
class Repository
{
	std::vector<Doctor> vectorOfAllDoctors;
	std::vector<Patient> vectorOfAllPatients;

	/*bool sortAccountsBySurname(const Account& account_1, const Account& account_2);

	void sortDoctorsBySurname(std::vector <Doctor>& employees);
	void sortPatientsBySurname(std::vector <Patient>& employees);*/

	/// <summary>
	/// Возвращает индекс аккаунта в векторе по логину. Если аккаунт не найден, возвращает -1.
	/// Если логин админа - -2.
	/// </summary>
	/// <param name="loginToFind">- логин аккаунта, индекс которого необходимо найти</param>
	/// <returns></returns>
	int getIndexByLogin(string loginToFind);

	friend class Administrator;

public:
	Account* checkLoginAndPassword(string login, string password, int role);
};

