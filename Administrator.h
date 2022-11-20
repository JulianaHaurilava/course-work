#pragma once
#include "Account.h"

#include "Doctor.h"
#include "Patient.h"
#include "Repository.h"
#include "Checkups.h"

#include <vector>
#include <string>
#include <algorithm>


using std::string;

class Administrator :
	public Account
{
	string doctorFileName = "not_verified_doctors_file";

	std::vector<Doctor> vectorOfNotVerifiedDoctors;

	int getIndexByLogin(string loginToFind);

	string getCorrectExistingLogin(std::istream& s, const char* message, Repository r);

	void allDoctorVectorInFile();

	void allDoctorVectorOutOfFile();

public:
	Administrator();
	~Administrator();

	void logInSystem() override;

	/// <summary>
	/// Добавляет нового доктора в вектор
	/// </summary>
	/// <param name="newPatient"> - </param>
	void addNewDoctor(Doctor newDoctor);
	/// <summary>
	/// Удаляет аккаунт по логину
	/// </summary>
	/// <param name="loginToDelete">- логин пользователя, которого нужно удалить</param>
	void deleteAccount(Repository r, string loginToDelete);

	void verifyAccount(Repository r, string login);

	Doctor findDoctorByLogin(string login);
};

