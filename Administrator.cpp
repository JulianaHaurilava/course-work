#include "Administrator.h"

string Administrator::getCorrectExistingLogin(std::istream& s, const char* message, Repository r)
{
	string adminInput;
	while (true)
	{
		try
		{
			std::cout << message;
			getline(std::cin, adminInput);

			int role = stoi(login.substr(0, 2));
			if (adminInput.length() != 16 ||
				role != 2 && role != 3)
			{
				throw -1;
			}
			if (role == 1) throw false;

			bool inVector = false;
			if (role == 2)
			{
				for (Doctor doctor : r.vectorOfAllDoctors)
				{
					if (adminInput == doctor.getLogin())
					{
						inVector == true;
						break;
					}
				}
			}
			else
			{
				for (Patient patient : r.vectorOfAllPatients)
				{
					if (adminInput == patient.getLogin())
					{
						inVector == true;
						break;
					}
				}
			}
			
			if (!inVector)
			{
				throw inVector;
			}
			return adminInput;
		}
		catch (bool)
		{
			std::cin.clear();
			std::cout << "Введенные данные некорректны! Пользователь с таким логином" <<
				"не зарегистрирован в системе.\n Повторите ввод.\n\n";
		}
		catch (std::invalid_argument)
		{
			std::cin.clear();
			std::cout << "Введенные данные некорректны! Введен неверный логин.\n" <<
				"Повторите ввод.\n\n";
		}
		catch (int)
		{
			std::cin.clear();
			std::cout << "Введенные данные некорректны! Введен неверный логин.\n" <<
				"Повторите ввод.\n\n";
		}
	}
}

void Administrator::allDoctorVectorInFile()
{
	std::ofstream fout;
	fout.open(doctorFileName, std::ios::trunc);

	if (!fout.is_open())
	{
		std::cout << "\nОшибка открытия файла!\n";
		return;
	}

	for (Doctor doctor : vectorOfNotVerifiedDoctors)
	{
		fout << doctor.getStringForFile();
	}

	fout.close();
}

void Administrator::allPatientVectorInFile()
{
	std::ofstream fout;
	fout.open(patientFileName, std::ios::trunc);

	if (!fout.is_open())
	{
		std::cout << "\nОшибка открытия файла!\n";
		return;
	}

	for (Patient patient : vectorOfNotVerifiedPatients)
	{
		fout << patient.getStringForFile();
	}

	fout.close();
}

void Administrator::allDoctorVectorOutOfFile()
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
		vectorOfNotVerifiedDoctors.push_back(doctor);

	} while (!fs.eof());

	if (vectorOfNotVerifiedDoctors.back().getLogin() == "_")
	{
		vectorOfNotVerifiedDoctors.pop_back();
	}
	fs.close();
}

void Administrator::allPatientVectorOutOfFile()
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
		vectorOfNotVerifiedPatients.push_back(patient);

	} while (!fs.eof());

	if (vectorOfNotVerifiedPatients.back().getLogin() == "_")
	{
		vectorOfNotVerifiedPatients.pop_back();
	}
	fs.close();
}

Administrator::Administrator()
{
	login = "0107112022134542";
	encryptedPassword = "some_password";
	access = true;

	allDoctorVectorOutOfFile();
	allPatientVectorOutOfFile();
}

Administrator::~Administrator()
{
	allDoctorVectorInFile();
	allPatientVectorInFile();
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

	int role = stoi(login.substr(0, 2));
	switch (role)
	{
	case 2:
		vectorOfNotVerifiedDoctors[indexToVerify].changeAccess();
		r.vectorOfAllDoctors.push_back(vectorOfNotVerifiedDoctors[indexToVerify]);
		vectorOfNotVerifiedDoctors.erase(vectorOfNotVerifiedDoctors.begin() + indexToVerify);
		break;
	case 3:
		string doctorLogin = getCorrectExistingLogin(std::cin, "Введите логин лечащего врача: ", r);
		vectorOfNotVerifiedPatients[indexToVerify].setDoctorLogin(doctorLogin);

		vectorOfNotVerifiedPatients[indexToVerify].changeAccess();
		r.vectorOfAllPatients.push_back(vectorOfNotVerifiedPatients[indexToVerify]);
		vectorOfNotVerifiedPatients.erase(vectorOfNotVerifiedPatients.begin() + indexToVerify);
		break;
	}
}

int Administrator::getIndexByLogin(string loginToFind)
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

}





