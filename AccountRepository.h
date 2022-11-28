#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

#include "Checkups.h"

using std::string;

//������� ������� ������� �� ������� ������ � ����!!! ���� ����� ����, ���������...
template <typename T>
class AccountRepository
{
	string fileName;
	std::vector<T> vectorOfAccounts;

	void allVectorInFile()
	{
		std::ofstream fout;
		fout.open(fileName, std::ios::trunc);

		if (!fout.is_open())
		{
			std::cout << "\n������ �������� �����!\n";
			return;
		}

		for (T info : vectorOfAccounts)
		{
			fout << info.getStringForFile();
		}

		fout.close();
	}

	void allVectorOutOfFile()
	{
		std::fstream fs;
		fs.open(fileName, std::ios::in | std::fstream::app);

		if (!fs.is_open())
		{
			std::cout << "\n������ �������� �����!\n";
			return;
		}

		do
		{
			T info = T();
			fs >> info;
			vectorOfAccounts.push_back(info);

		} while (!fs.eof());

		if (vectorOfAccounts.back().getLogin() == "_")
		{
			vectorOfAccounts.pop_back();
		}
		fs.close();
	}

	int getIndexByLogin(string loginToFind)
	{
		int vectorSize = vectorOfAccounts.size();
		for (int i = 0; i < vectorSize; i++)
		{
			if (vectorOfAccounts[i].getLogin() == loginToFind)
			{
				return i;
			}
		}
		return -1;
	}

public:

	AccountRepository(string fileName)
	{
		this->fileName = fileName;
		allVectorOutOfFile();
	}
	~AccountRepository()
	{
		allVectorInFile();
	}

	T findAccountByLogin(string login)
	{
		int index = getIndexByLogin(login);
		if (index != -1)
		{
			return vectorOfAccounts[index];
		}
		return T();
	}


	void addNewAccount(T newAccount)
	{
		vectorOfAccounts.push_back(newAccount);
	}

	/// <summary>
/// ������� ������� �� ������
/// </summary>
/// <param name="loginToDelete">- ����� ������������, �������� ����� �������</param>
	void deleteAccount(string loginToDelete)
	{
		int indexToDelete = getIndexByLogin(loginToDelete);
		if (indexToDelete != -1)
		{
			vectorOfAccounts.erase(vectorOfAccounts.begin() + indexToDelete);
			allVectorInFile();
			return;
		}
		std::cout << "������� � ����� ������� �� ��������������� � �������!\n";
	}

	void printAllAccounts()
	{
		for (T vectorItem : vectorOfAccounts)
		{
			vectorItem.print();
			std::cout << std::endl;
		}
	}

	void printAccountByLogin(string loginToPrint)
	{
		int indexToPrint = getIndexByLogin(loginToPrint);
		if (indexToPrint != -1)
		{
			std::cout << std::endl;
			vectorOfAccounts[indexToPrint].print();
			std::cout << std::endl;
			return;
		}

		std::cout << "������� � ����� ������� �� ��������������� � �������!\n";
	}

	T changeAccess(string loginToVerify)
	{
		int indexToVerify = getIndexByLogin(loginToVerify);
		if (indexToVerify == -1)
		{
			return T();
		}

		vectorOfAccounts[indexToVerify].enableAccess();
		return vectorOfAccounts[indexToVerify];
	}
};


