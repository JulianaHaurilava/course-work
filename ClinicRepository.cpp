#include "ClinicRepository.h"


void ClinicRepository::allServiceMapInFile()
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

		if (serviceName != "")
			allServices.insert(std::pair<string, double>(serviceName, servicePrice));

	} while (!fs.eof());


	fs.close();
}

void ClinicRepository::addServiceInFile(string serviceName)
{
	std::ofstream fout;
	fout.open(serviceFileName, std::ios::app);

	if (!fout.is_open())
	{
		std::cout << "\nОшибка открытия файла!\n";
		return;
	}

	fout << std::to_string(allServices.find(serviceName)->second) + " " +
		allServices.find(serviceName)->first + '\n';

	fout.close();
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
	std::cout << std::setw(25) << "Название услуги" << "   " << "Цена" << std::endl << std::endl;
	for (auto& service : allServices)
	{
		std::cout << std::setw(25) << service.first << "   " << service.second << " BYN" << std::endl;
	}
}

void ClinicRepository::addNewService(string name, double price)
{
	allServices.insert(std::pair<string, double>(name, price));
	addServiceInFile(name);
}

void ClinicRepository::deleteService(string name)
{
	if (allServices.erase(name))
	{
		allServiceMapInFile();
		std::cout << "Выбранная услуга успешно удалена!\n";
		return;
	}
	else std::cout << "Услуга не найдена!\n";
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
		std::cout << "\nЧто вы хотите сделать? Выберите соответствующее число.\n"
			"1 - редактировать название услуги;\n"
			"2 - редактировать цену услуги;\n"
			"3 - выйти;\n\n";

		int choice = chps::getCorrectMenuInput(3);
		system("cls");

		switch (choice)
		{
		case 1:
		{
			string newName = chps::getCorrectStringInput(std::cin, "Новое название услуги: ");
			double oldPrice = foundService->second;
			allServices.erase(foundService);

			allServices[newName] = oldPrice;

			allServiceMapInFile();
			std::cout << "Данные успешно изменены!\n";
			return;
		}
		case 2:
		{
			double newPrice = chps::getCorrectPositiveDouble(std::cin, "Новая цена услуги: ");
			foundService->second = newPrice;

			allServiceMapInFile();
			std::cout << "Данные успешно изменены!\n";
			return;
		}
		case 3:
			return;
		}
	}
	std::cout << "Услуга не найдена!\n";
}


