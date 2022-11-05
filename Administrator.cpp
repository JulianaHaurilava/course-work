#include "Administrator.h"

void Administrator::addNewDoctor(Doctor newDoctor)
{
	vectorOfAllDoctors.push_back(newDoctor);
	newDoctor.changeAccess();
}

void Administrator::addNewPatient(Doctor newPatient)
{
	vectorOfAllPatients.push_back(newPatient);
	newPatient.changeAccess();
}

// ����� ����� ���������� ����� (��������)
void Administrator::deleteAccount(string loginToDelete) 
{
	int role = stoi(loginToDelete.substr(0, 2));
	switch (role)
	{
	case 1:
		std::cout << "�������� ������������ �������� ����������!";
		break;
	case 2:
		vectorOfAllDoctors.erase(vectorOfAllDoctors.begin() +
			getIndexByLogin(loginToDelete));
		break;
	case 3:
		vectorOfAllPatients.erase(vectorOfAllPatients.begin() +
			getIndexByLogin(loginToDelete));
		break;
	}
}

// ���������� -2 ���� ����� � -1 ���� �� �����
int Administrator::getIndexByLogin(string loginToFind)
{
	int role = stoi(loginToFind.substr(0, 2));
	switch (role)
	{
	case 1:
		std::cout << "�������������� �������� �������������� ����������!";
		return -2;
	case 2:
		int vectorSize = vectorOfAllDoctors.size();
		for (int i = 0; i < vectorSize; i++)
		{
			if (vectorOfAllDoctors[i].getLogin() == loginToFind)
			{
				return i;
			}
		}
		break;
	case 3:
		int vectorSize = vectorOfAllPatients.size();
		for (int i = 0; i < vectorSize; i++)
		{
			if (vectorOfAllPatients[i].getLogin() == loginToFind)
			{
				return i;
			}
		}
		break;
	}
	return -1;
} // ���������� -2 ���� ����� � -1 ���� 


