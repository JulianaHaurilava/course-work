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

Doctor Repository::findDoctorByLogin(string login)
{
	int index = getIndexByLogin(login);
	if (index != -1)
	{
		return vectorOfAllDoctors[index];
	}
	return Doctor();
}

Patient Repository::findPatientByLogin(string login)
{
	int index = getIndexByLogin(login);
	if (index != -1)
	{
		return vectorOfAllPatients[index];
	}
	return Patient();
}


