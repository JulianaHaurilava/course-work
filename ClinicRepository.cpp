#include "ClinicRepository.h"


void ClinicRepository::allServiceMapInFile()
{

	std::ofstream fout;
	fout.open(serviceFileName, std::ios::trunc);

	if (!fout.is_open())
	{
		std::cout << "\n������ �������� �����!\n";
		return;
	}

	for (auto& serviceInfo : allServices)
	{
		fout << std::to_string(serviceInfo.second) + " " + serviceInfo.first + '\n';
	}

	fout.close();
}

void ClinicRepository::allServiceMapOutOfFile()
{
	std::fstream fs;
	fs.open(serviceFileName, std::ios::in | std::fstream::app);

	if (!fs.is_open())
	{
		std::cout << "\n������ �������� �����!\n";
		return;
	}

	do
	{
		double servicePrice;
		fs >> servicePrice;

		string serviceName;
		fs.get();
		getline(fs, serviceName);

		if (serviceName != "")
			allServices.insert(std::pair<string, double>(serviceName, servicePrice));

	} while (!fs.eof());


	fs.close();
}

ClinicRepository::ClinicRepository()
{
	allServiceMapOutOfFile();
}

ClinicRepository::~ClinicRepository()
{
	allServiceMapInFile();
}

void ClinicRepository::printTableOfServices()
{
	std::cout << std::setw(20) << "�������� ������" << "   " << "����" << std::endl;
	for (auto& service : allServices)
	{
		std::cout << std::setw(20) << service.first << "   " << service.second << std::endl;
	}
}

void ClinicRepository::addNewService(string name, double price)
{
	allServices.insert(std::pair<string, double>(name, price));
}

void ClinicRepository::deleteService(string name)
{
	if (allServices.erase(name))
	{
		return;
	}
	else std::cout << "������ �� �������!\n";
}

double ClinicRepository::getPriceByName(string name)
{
	auto foundService = allServices.find(name);
	if (!(foundService == allServices.end()))
	{
		return foundService->second;
	}
	return 0;
}

void ClinicRepository::editService(string name)
{
	auto foundService = allServices.find(name);
	if (!(foundService == allServices.end()))
	{
		std::cout << "\n��� �� ������ �������? �������� ��������������� �����.\n"
			"1 - ������������� �������� ������;\n"
			"2 - ������������� ���� ������;\n"
			"3 - �����;\n\n";

		int choice = getCorrectMenuInput(3);
		system("cls");

		switch (choice)
		{
		case 1:
		{
			string newName = getCorrectStringInput(std::cin, "����� �������� ������: ");
			double oldPrice = foundService->second;
			allServices.erase(foundService);

			allServices[newName] = oldPrice;
			return;
		}
		case 2:
		{
			double newPrice = getCorrectPositiveDouble(std::cin, "����� ���� ������: ");
			foundService->second = newPrice;
			return;
		}
		case 3:
			return;
		}
		endCase();
	}
	std::cout << "������ �� �������!\n";
}


