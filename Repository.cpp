#include "Repository.h"

Repository::Repository()
{
	allVectorOutOfFile(vectorOfAllDoctors, doctorFileName);
	allVectorOutOfFile(vectorOfNotVerifiedDoctors, doctorNonVerifiedFileName);
	allVectorOutOfFile(vectorOfAllPatients, patientFileName);

	allServiceMapOutOfFile();
}

Repository::~Repository()
{
	allVectorInFile(vectorOfAllDoctors, doctorFileName);
	allVectorInFile(vectorOfNotVerifiedDoctors, doctorNonVerifiedFileName);
	allVectorInFile(vectorOfAllPatients, patientFileName);

	allServiceMapInFile();
}

void Repository::allServiceMapInFile()
{
	
	std::ofstream fout;
	fout.open(serviceFileName, std::ios::trunc);

	if (!fout.is_open())
	{
		std::cout << "\nОшибка открытия файла!\n";
		return;
	}

	for (auto& serviceInfo : allServices)
	{
		fout << std::to_string(serviceInfo.second) + " " +  serviceInfo.first + '\n';
	}

	fout.close();
}

void Repository::allServiceMapOutOfFile()
{
	std::fstream fs;
	fs.open(serviceFileName, std::ios::in | std::fstream::app);

	if (!fs.is_open())
	{
		std::cout << "\nОшибка открытия файла!\n";
		return;
	}

	do
	{
		double servicePrice;
		fs >> servicePrice;

		string serviceName;
		fs.get();
		getline(fs, serviceName);

		if (servicePrice < 0)
			allServices.insert(std::pair<string, double>(serviceName, servicePrice));

	} while (!fs.eof());


	fs.close();
}


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

void Repository::addNewPatient(Patient newPatient)
{
	vectorOfAllPatients.push_back(newPatient);
}

int Repository::getNonVerifiedIndexByLogin(string loginToFind)
{
	int role = stoi(loginToFind.substr(0, 2));

	if (role == 2)
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
	return -1;
}

Doctor Repository::findNotVerifiedDoctorByLogin(string login)
{
	int index = getNonVerifiedIndexByLogin(login);
	if (index != -1)
	{
		return vectorOfNotVerifiedDoctors[index];
	}
	return Doctor();
}

void Repository::addNewDoctor(Doctor newDoctor)
{
	vectorOfNotVerifiedDoctors.push_back(newDoctor);
}

void Repository::deleteAccount(string loginToDelete)
{
	int indexToDelete = getIndexByLogin(loginToDelete);

	int role = stoi(loginToDelete.substr(0, 2));

	switch (role)
	{
	case 2:
		vectorOfAllDoctors.erase(vectorOfAllDoctors.begin() +
			indexToDelete);
		break;
	case 3:
		vectorOfAllPatients.erase(vectorOfAllPatients.begin() +
			indexToDelete);
		break;
	}
}

void Repository::verifyAccount(string login)
{
	int indexToVerify = getNonVerifiedIndexByLogin(login);
	if (indexToVerify == -1)
	{
		std::cout << "Пользовательские аккаунты не требуют верификации\n";
		return;
	}

	int role = stoi(login.substr(0, 2));

	vectorOfNotVerifiedDoctors[indexToVerify].changeAccess();
	vectorOfAllDoctors.push_back(vectorOfNotVerifiedDoctors[indexToVerify]);
	vectorOfNotVerifiedDoctors.erase(vectorOfNotVerifiedDoctors.begin() + indexToVerify);
}


