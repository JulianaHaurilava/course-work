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

		if (servicePrice > 0)
			allServices.insert(std::pair<string, double>(serviceName, servicePrice));

	} while (!fs.eof());


	fs.close();
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

Doctor Repository::findNotVerifiedDoctorByLogin(string login)
{
	int index = getNonVerifiedIndexByLogin(login);
	if (index != -1)
	{
		return vectorOfNotVerifiedDoctors[index];
	}
	return Doctor();
}


void Repository::addNewPatient(Patient newPatient)
{
	vectorOfAllPatients.push_back(newPatient);
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

void Repository::printTableOfServices()
{
	std::cout << '|' << std::setw(15) << "Название услуги" << std::setw(6) 
		<< '|' << std::setw(7)  << "Цена" << std::setw(2) << '|' << std::endl;
	for (auto& service : allServices)
	{
		std::cout << '|' << std::setw(19) << service.first << std::setw(2)
			<< '|' << std::setw(7) << std::setprecision(6) << service.second << std::setw(2)
			<< '|' << std::endl;
	}
}

void Repository::addNewService(string name, double price)
{
	allServices.insert(std::pair<string, double>(name, price));
}

void Repository::deleteService(string name)
{
	if (allServices.erase(name))
	{
		return;
	}
	else std::cout << "Услуга не найдена!\n";
}

double Repository::getPriceByName(string name)
{
	auto foundService = allServices.find(name);
	if (!(foundService == allServices.end()))
	{
		return foundService->second;
	}
	return 0;
}

void Repository::editService(string name)
{
	auto foundService = allServices.find(name);
	if (!(foundService == allServices.end()))
	{
		std::cout << "\nЧто вы хотите сделать? Выберите соответствующее число.\n"
			"1 - редактировать название услуги;\n"
			"2 - редактировать цену услуги;\n"
			"3 - выйти;\n\n";

		int choice = getCorrectMenuInput(3);
		system("cls");

		switch (choice)
		{
		case 1:
		{
			string newName = getCorrectStringInput(std::cin, "Новое название услуги: ");
			double oldPrice = foundService->second;
			allServices.erase(foundService);

			allServices[newName] = oldPrice;
			break;
		}
		case 2:
		{
			double newPrice = getCorrectPositiveDouble(std::cin, "Новая цена услуги: ");
			foundService->second = newPrice;

			break;
		}
		case 3:
			return;
		}
		endCase();
	}
	std::cout << "Услуга не найдена!\n";
}






