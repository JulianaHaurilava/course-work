#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

#include "Checkups.h"

using std::string;

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
			std::cout << "\nОшибка открытия файла!\n";
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
/// Удаляет аккаунт по логину
/// </summary>
/// <param name="loginToDelete">- логин пользователя, которого нужно удалить</param>
	void deleteAccount(string loginToDelete)
	{
		int indexToDelete = getIndexByLogin(loginToDelete);
		vectorOfAccounts.erase(vectorOfAccounts.begin() + indexToDelete);
	}

	void printAllAccounts()
	{
		for (T vectorItem : vectorOfAccounts)
		{
			vectorItem.print();
			std::cout << std::endl;
		}
	}

	bool changeAccess(string loginToVerify)
	{
		int indexToVerify = getIndexByLogin(loginToVerify);
		if (indexToVerify == -1)
		{
			std::cout << "Аккаунт с таким логином не зарегистрирован в системе!\n";
			return false;
		}
		vectorOfAccounts[indexToVerify].changeAccess();
		return true;
	}

};


