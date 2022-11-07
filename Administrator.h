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
public:
	Administrator();

	void logInSystem() override;

	/// <summary>
	/// Добавляет нового доктора в вектор и разрешает доступ к его аккаунту (верификация)
	/// </summary>
	/// <param name="newPatient"> - </param>
	void addNewDoctor(Repository r, Doctor newDoctor);

	/// <summary>
	/// Добавляет нового пациента в вектор и разрешает доступ к его аккаунту (верификация)
	/// </summary>
	/// <param name="newPatient"> - </param>
	void addNewPatient(Repository r,Patient newPatient);

	/// <summary>
	/// Удаляет аккаунт по логину
	/// </summary>
	/// <param name="loginToDelete">- логин пользователя, которого нужно удалить</param>
	void deleteAccount(Repository r, string loginToDelete);

	
};

