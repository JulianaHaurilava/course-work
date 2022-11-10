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

	int getIndexByLogin(string loginToFind);

	string getCorrectExistingLogin(std::istream& s, const char* message, Repository r);

public:
	Administrator();

	void logInSystem() override;

	/// <summary>
	/// Добавляет нового доктора в вектор
	/// </summary>
	/// <param name="newPatient"> - </param>
	void addNewDoctor(Doctor newDoctor);

	/// <summary>
	/// Добавляет нового пациента в вектор
	/// </summary>
	/// <param name="newPatient"> - </param>
	void addNewPatient(Patient newPatient);

	/// <summary>
	/// Удаляет аккаунт по логину
	/// </summary>
	/// <param name="loginToDelete">- логин пользователя, которого нужно удалить</param>
	void deleteAccount(Repository r, string loginToDelete);

	void verifyAccount(Repository r, string login);

	
	
};

