#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>

#include "Checkups.h"
#include "FullName.h"

using std::string;

template <typename T>
class AccountRepository
{
	string fileName;
	std::vector<T> vectorOfAccounts;

	

	void allVectorOutOfFile()
	{
		std::fstream fs;
		fs.open(fileName, std::ios::in | std::fstream::app);

		if (!fs.is_open())
		{
			std::cout << "\nОшибка открытия файла!\n";
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

	void lastAccountInFile()
	{
		std::ofstream fout;
		fout.open(fileName, std::ios::app);

		if (!fout.is_open())
		{
			std::cout << "\nОшибка открытия файла!\n";
			return;
		}

		fout << vectorOfAccounts.back().getStringForFile();
		fout.close();
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

	int getIndexByFullName(FullName fullName)
	{
		int vectorSize = vectorOfAccounts.size();
		for (int i = 0; i < vectorSize; i++)
		{
			if (vectorOfAccounts[i].getFullName() == fullName)
			{
				return i;
			}
		}
		return -1;
	}

	void allVectorInFile()
	{
		std::ofstream fout;
		fout.open(fileName, std::ios::trunc);

		if (!fout.is_open())
		{
			std::cout << "\nОшибка открытия файла!\n";
			return;
		}

		for (T info : vectorOfAccounts)
		{
			fout << info.getStringForFile();
		}

		fout.close();
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

	T* findAccountByLogin(string login)
	{
		int index = getIndexByLogin(login);
		if (index != -1)
		{
			return &vectorOfAccounts[index];
		}
		return new T();
	}

	T* findAccountByFullName(FullName fullName)
	{
		int index = getIndexByFullName(fullName);
		if (index != -1)
		{
			return &vectorOfAccounts[index];
		}

		T* emptyT = new T();
		return emptyT;
	}

	void addNewAccount(T newAccount)
	{
		vectorOfAccounts.push_back(newAccount);
		lastAccountInFile();
	}

	/// <summary>
/// Удаляет аккаунт по логину
/// </summary>
/// <param name="loginToDelete">- логин пользователя, которого нужно удалить</param>
	void deleteAccount(string loginToDelete)
	{
		int indexToDelete = getIndexByLogin(loginToDelete);
		if (indexToDelete != -1)
		{
			vectorOfAccounts.erase(vectorOfAccounts.begin() + indexToDelete);
			allVectorInFile();
			return;
		}
		std::cout << "Аккаунт с таким логином не зарегистрирован в системе!\n";
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

		std::cout << "Аккаунт с таким логином не зарегистрирован в системе!\n";
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

	void updateRepository()
	{
		allVectorInFile();
	}
};


