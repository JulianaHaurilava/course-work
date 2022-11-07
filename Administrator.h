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
	/// ��������� ������ ������� � ������ � ��������� ������ � ��� �������� (�����������)
	/// </summary>
	/// <param name="newPatient"> - </param>
	void addNewDoctor(Repository r, Doctor newDoctor);

	/// <summary>
	/// ��������� ������ �������� � ������ � ��������� ������ � ��� �������� (�����������)
	/// </summary>
	/// <param name="newPatient"> - </param>
	void addNewPatient(Repository r,Patient newPatient);

	/// <summary>
	/// ������� ������� �� ������
	/// </summary>
	/// <param name="loginToDelete">- ����� ������������, �������� ����� �������</param>
	void deleteAccount(Repository r, string loginToDelete);

	
};

