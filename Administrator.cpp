#include "Administrator.h"

Administrator::Administrator()
{
	login = "0107112022134542";
	encryptedPassword = "some_password";
	access = true;
}

void Administrator::logInSystem()
{
}

void Administrator::addNewDoctor(Repository r, Doctor newDoctor)
{
	r.vectorOfAllDoctors.push_back(newDoctor);
	newDoctor.changeAccess();
}

void Administrator::addNewPatient(Repository r, Patient newPatient)
{
	r.vectorOfAllPatients.push_back(newPatient);
	newPatient.changeAccess();
}

void Administrator::deleteAccount(Repository r, string loginToDelete)
{
	int indexToDelete = r.getIndexByLogin(loginToDelete);
	if (indexToDelete == -1)
	{
		std::cout << "Такой аккаунт не зарегистрирован в системе!\n";
		return;
	}
	else if (indexToDelete == -2)
	{
		std::cout << "Нельзя удалить аккаунт администратора!\n";
		return;
	}

	int role = stoi(loginToDelete.substr(0, 2));

	switch (role)
	{
	case 2:
		r.vectorOfAllDoctors.erase(r.vectorOfAllDoctors.begin() +
			r.getIndexByLogin(loginToDelete));
		break;
	case 3:
		r.vectorOfAllPatients.erase(r.vectorOfAllPatients.begin() +
			r.getIndexByLogin(loginToDelete));
		break;
	}
}





