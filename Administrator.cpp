#include "Administrator.h"

string Administrator::getCorrectExistingLogin(std::istream& s, const char* message, Repository r) //��������
{
	string adminInput;
	while (true)
	{
		try
		{
			std::cout << message;
			getline(std::cin, adminInput);

			//�������� ���� � �����
			//��������� ���� �� � �������

			if (userIntInput <= 0) throw - 1;
			return userIntInput;
		}
		catch (const char*)
		{
			std::cin.clear();
			std::cout << "��������� ������ �����������! ���������� ����� �� �������� �����.\n" <<
				"��������� ����.\n\n";
		}
		catch (std::invalid_argument)
		{
			std::cin.clear();
			std::cout << "��������� ������ �����������! ���� �������� ������������ �������.\n" <<
				"��������� ����.\n\n";
		}
		catch (int)
		{
			std::cin.clear();
			std::cout << "��������� ������ �����������! ��������� ����� �� �������������.\n" <<
				"��������� ����.\n\n";
		}
	}
}


Administrator::Administrator()
{
	login = "0107112022134542";
	encryptedPassword = "some_password";
	access = true;
}

void Administrator::logInSystem()
{
	
}

void Administrator::addNewDoctor(Doctor newDoctor)
{
	vectorOfNotVerifiedDoctors.push_back(newDoctor);
}

void Administrator::addNewPatient(Patient newPatient)
{
	vectorOfNotVerifiedPatients.push_back(newPatient);
}

void Administrator::deleteAccount(Repository r, string loginToDelete)
{
	int indexToDelete = r.getIndexByLogin(loginToDelete);
	if (indexToDelete == -1)
	{
		std::cout << "����� ������� �� ��������������� � �������!\n";
		return;
	}
	else if (indexToDelete == -2)
	{
		std::cout << "������ ������� ������� ��������������!\n";
		return;
	}

	int role = stoi(loginToDelete.substr(0, 2));

	switch (role)
	{
	case 2:
		r.vectorOfAllDoctors.erase(r.vectorOfAllDoctors.begin() +
			indexToDelete);
		break;
	case 3:
		r.vectorOfAllPatients.erase(r.vectorOfAllPatients.begin() +
			indexToDelete);
		break;
	}
}

void Administrator::verifyAccount(Repository r, string login)
{
	int indexToVerify = getIndexByLogin(login);

	if (indexToVerify != -1 && indexToVerify != -2)
	{
		int role = stoi(login.substr(0, 2));
		switch (role)
		{
		case 2:
			vectorOfNotVerifiedDoctors[indexToVerify].changeAccess();
			r.vectorOfAllDoctors.push_back(vectorOfNotVerifiedDoctors[indexToVerify]);
			vectorOfNotVerifiedDoctors.erase(vectorOfNotVerifiedDoctors.begin() + indexToVerify);
			break;
		case 3: //� ���. ��������� ��������?
			std::cout << "������� ����� �������� �����: ";
			string doctorLogin = get 
			vectorOfNotVerifiedPatients[indexToVerify].setDoctorLogin(doctorLogin);
			vectorOfNotVerifiedPatients[indexToVerify].changeAccess();
			r.vectorOfAllPatients.push_back(vectorOfNotVerifiedPatients[indexToVerify]);
			vectorOfNotVerifiedPatients.erase(vectorOfNotVerifiedPatients.begin() + indexToVerify);
			break;
		}
	}
	else
	{
		std::cout << "������������ � ����� ������� ��� � ����!\n\n";
	}



}

int Administrator::getIndexByLogin(string loginToFind)
{
	int role = stoi(loginToFind.substr(0, 2));
	if (role == 1)
		return -2;
	else if (role == 2)
	{
		int vectorSize = vectorOfNotVerifiedDoctors.size();
		for (int i = 0; i < vectorSize; i++)
		{
			if (vectorOfNotVerifiedDoctors[i].getLogin() == loginToFind)
			{
				return i;
			}
		}
	}
	else if (role == 3)
	{
		int vectorSize = vectorOfNotVerifiedPatients.size();
		for (int i = 0; i < vectorSize; i++)
		{
			if (vectorOfNotVerifiedPatients[i].getLogin() == loginToFind)
			{
				return i;
			}
		}
	}
	return -1;
}





