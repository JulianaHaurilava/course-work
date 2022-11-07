#include "Repository.h"

int Repository::getIndexByLogin(string loginToFind)
{
	int role = stoi(loginToFind.substr(0, 2));
	if (role == 1)
		return -2;
	else if (role == 2)
	{
		int vectorSize = vectorOfAllDoctors.size();
		for (int i = 0; i < vectorSize; i++)
		{
			if (vectorOfAllDoctors[i].getLogin() == loginToFind)
			{
				return i;
			}
		}
	}
	else if (role == 3)
	{
		int vectorSize = vectorOfAllPatients.size();
		for (int i = 0; i < vectorSize; i++)
		{
			if (vectorOfAllPatients[i].getLogin() == loginToFind)
			{
				return i;
			}
		}
	}
	return -1;
}

Account* Repository::checkLoginAndPassword(string login, string password, int role)
{
	int index = getIndexByLogin(login);

	if (index == -1)
	{
		return false;
	}
	else
	{
		Hash h;
		string encryptedPassword = h.getHash(password, 12);

		if (role == 1)
		{
			Administrator admin;
			if (!(login == admin.getLogin() && encryptedPassword == admin.getEncryptedPassword()))
				admin.changeAccess();
			return &admin;
		}
		if (role == 2)
		{
			Doctor doctor = vectorOfAllDoctors[index];
			if (!(login == doctor.getLogin() && encryptedPassword == doctor.getEncryptedPassword()))
				doctor = Doctor();
			return &doctor;

		}
		else if (role == 3)
		{
			Patient patient = vectorOfAllPatients[index];
			if (!(login == patient.getLogin() && encryptedPassword == patient.getEncryptedPassword()))
				patient = Patient();
			return &patient;
		}
	}
}

