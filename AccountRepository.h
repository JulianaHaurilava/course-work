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

	void allVectorOutOfFile();

	void lastAccountInFile();

	int getIndex(string loginToFind);

	int getIndex(FullName fullName);

	void allVectorInFile();

public:
	
	AccountRepository(string fileName);

	~AccountRepository();

	T* findAccountByLogin(string login);

	T* findAccountByFullName(FullName fullName);

	void addNewAccount(T newAccount);

	void deleteAccount(string loginToDelete);

	void printAllAccounts();

	void printAccountByLogin(string loginToPrint);

	T changeAccess(string loginToVerify);

	void updateRepository();
};

template<typename T>
inline void AccountRepository<T>::allVectorOutOfFile()
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

template<typename T>
inline void AccountRepository<T>::lastAccountInFile()
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

template<typename T>
inline int AccountRepository<T>::getIndex(string loginToFind)
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

template<typename T>
inline int AccountRepository<T>::getIndex(FullName fullName)
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

template<typename T>
inline void AccountRepository<T>::allVectorInFile()
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

template<typename T>
inline AccountRepository<T>::AccountRepository(string fileName)
{
	this->fileName = fileName;
	allVectorOutOfFile();
}

template<typename T>
inline AccountRepository<T>::~AccountRepository()
{
	allVectorInFile();
}

template<typename T>
inline T* AccountRepository<T>::findAccountByLogin(string login)
{
	int index = getIndex(login);
	if (index != -1)
	{
		return &vectorOfAccounts[index];
	}
	return new T();
}

template<typename T>
inline T* AccountRepository<T>::findAccountByFullName(FullName fullName)
{
	int index = getIndex(fullName);
	if (index != -1)
	{
		return &vectorOfAccounts[index];
	}

	T* emptyT = new T();
	std::unique_ptr<T> unEmptyT = std::make_unique<T>();
	return emptyT;
}

template<typename T>
inline void AccountRepository<T>::addNewAccount(T newAccount)
{
	vectorOfAccounts.push_back(newAccount);
	lastAccountInFile();
}

template<typename T>
inline void AccountRepository<T>::deleteAccount(string loginToDelete)
{
	int indexToDelete = getIndex(loginToDelete);
	if (indexToDelete != -1)
	{
		vectorOfAccounts.erase(vectorOfAccounts.begin() + indexToDelete);
		allVectorInFile();
		return;
	}
	std::cout << "Аккаунт с таким логином не зарегистрирован в системе!\n";
}

template<typename T>
inline void AccountRepository<T>::printAllAccounts()
{
	for (T vectorItem : vectorOfAccounts)
	{
		vectorItem.print();
		std::cout << std::endl;
	}
}

template<typename T>
inline void AccountRepository<T>::printAccountByLogin(string loginToPrint)
{
	int indexToPrint = getIndex(loginToPrint);
	if (indexToPrint != -1)
	{
		std::cout << std::endl;
		vectorOfAccounts[indexToPrint].print();
		std::cout << std::endl;
		return;
	}

	std::cout << "Аккаунт с таким логином не зарегистрирован в системе!\n";
}

template<typename T>
inline T AccountRepository<T>::changeAccess(string loginToVerify)
{
	int indexToVerify = getIndex(loginToVerify);
	if (indexToVerify == -1)
	{
		return T();
	}

	vectorOfAccounts[indexToVerify].enableAccess();
	return vectorOfAccounts[indexToVerify];
}

template<typename T>
inline void AccountRepository<T>::updateRepository()
{
	allVectorInFile();
}
