#include "Repository.h"

Repository::Repository()
{
	allDoctorVectorOutOfFile();
	allPatientVectorOutOfFile();
}

Repository::~Repository()
{
	allDoctorVectorInFile();
	allPatientVectorInFile();
}

void Repository::allDoctorVectorInFile()
{
	std::ofstream fout;
	fout.open(doctorFileName, std::ios::trunc);

	if (!fout.is_open())
	{
		std::cout << "\nОшибка открытия файла!\n";
		return;
	}

	for (Doctor doctor : vectorOfAllDoctors)
	{
		fout << doctor.getStringForFile();
	}

	fout.close();
}

void Repository::allPatientVectorInFile()
{
	std::ofstream fout;
	fout.open(patientFileName, std::ios::trunc);

	if (!fout.is_open())
	{
		std::cout << "\nОшибка открытия файла!\n";
		return;
	}

	for (Patient patient : vectorOfAllPatients)
	{
		fout << patient.getStringForFile();
	}

	fout.close();
}

void Repository::allDoctorVectorOutOfFile()
{
	std::fstream fs;
	fs.open(doctorFileName, std::ios::in | std::fstream::app);

	if (!fs.is_open())
	{
		std::cout << "\nОшибка открытия файла!\n";
		return;
	}

	do
	{
		Doctor doctor = Doctor();
		fs >> doctor;
		vectorOfAllDoctors.push_back(doctor);

	} while (!fs.eof());

	if (vectorOfAllDoctors.back().getLogin() == "_")
	{
		vectorOfAllDoctors.pop_back();
	}
	fs.close();
}

void Repository::allPatientVectorOutOfFile()
{
	std::fstream fs;
	fs.open(patientFileName, std::ios::in | std::fstream::app);

	if (!fs.is_open())
	{
		std::cout << "\nОшибка открытия файла!\n";
		return;
	}

	do
	{
		Patient patient = Patient();
		fs >> patient;
		vectorOfAllPatients.push_back(patient);

	} while (!fs.eof());

	if (vectorOfAllPatients.back().getLogin() == "_")
	{
		vectorOfAllPatients.pop_back();
	}
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


