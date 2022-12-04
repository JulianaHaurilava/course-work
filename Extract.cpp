#include "Extract.h"
#include <iomanip>

Extract::Extract()
{
	diagnosis = "_";
	totalPrice = 0;
	recommendations = "_";
}

string Extract::getStringForFile()
{
	string stringForFile = "";
	stringForFile += diagnosis + '\n' + recommendations + '\n';

	if (!mapOfPaidServices.empty())
	{
		stringForFile += "p ";

		for (const auto& serviceInfo : mapOfPaidServices)
		{
			stringForFile += serviceInfo.first + " " + std::to_string(serviceInfo.second) + " ";
		}

		stringForFile.pop_back();
		stringForFile.push_back('\n');
	}
	
	return stringForFile;
}

void Extract::print()
{
	if (diagnosis != "_")
	{
		std::cout << "�������: " << diagnosis << std::endl;
		std::cout << "������������: " << recommendations << std::endl << std::endl;

		if (totalPrice != 0)
		{
			std::cout << std::setw(20) << "������" << "   " << "����" << std::endl;

			for (const auto& serviceInfo : mapOfPaidServices)
			{
				std::cout << std::setw(20) << serviceInfo.first << "   " << serviceInfo.second << std::endl;
			}

			std::cout << std::endl;
			std::cout << "�������� ����: " << totalPrice << " BYN" << std::endl;
		}
	}
	else std::cout << "\n� ��� ��� ��� �������\n";
}

void Extract::printExtractForDoctor()
{
	std::cout << "�������: " << diagnosis << std::endl;
	std::cout << "������������: " << recommendations << std::endl << std::endl;

	if (totalPrice != 0)
	{
		std::cout << "��������� ������" << std::endl;
		for (const auto& serviceInfo : mapOfPaidServices)
		{
			std::cout << serviceInfo.first << std::endl;
		}
	}
}

void Extract::setDiagnosis(string diagnosis)
{
	this->diagnosis = diagnosis;
}

void Extract::setRecommendations(string recommendations)
{
	this->recommendations = recommendations;
}

void Extract::setMap(std::map<string, double> mapOfPaidServices)
{
	totalPrice = 0;
	this->mapOfPaidServices.swap(mapOfPaidServices);
	
	for (const auto& serviceInfo : this->mapOfPaidServices)
	{
		totalPrice += serviceInfo.second;
	}
}

std::istream& operator >> (std::istream& in, Extract& extract)
{
	in.get();
	getline(in, extract.diagnosis);
	getline(in, extract.recommendations);
	extract.totalPrice = 0;

	if (in.peek() == 'p')
	{
		char nextChar = in.get();
		int i = 0;
		while (nextChar != '\n')
		{
			string buff;
			string serviceName;
			double servicePrice;
			in >> buff;

			while (buff[0] < 48 || buff[0] > 58)
			{
				serviceName += buff + " ";
				in >> buff;
			}
			serviceName.pop_back();
			servicePrice = stod(buff);

			extract.totalPrice += servicePrice;
			extract.mapOfPaidServices.insert({ serviceName, servicePrice });
			nextChar = in.peek();
		}
		in.get();
	}
	return in;
}
