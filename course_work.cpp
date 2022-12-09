#include "Administrator.h"

#include <iostream>
#include <windows.h>

void logInSystem(AccountRepository<Doctor>& dr, AccountRepository<Doctor>& ndr,
    AccountRepository<Patient>& pr, ClinicRepository& cr)
{
    string login, password;

    std::cout << "Введите логин: ";
    std::cin >> login;
    int role = chps::getRole(login);

    std::cout << "Введите пароль: ";

    char c;
    while ((c = _getch()) != '\r')
    {
        if (c == '\b')
        {
            std::cout << "\b \b";
            password.pop_back();
            continue;
        }
        password += c;
        _putch('*');
    }

    if (role == 1)
    {
        Administrator admin;
        if (admin.loginAndPasswordCorrect(login, password))
        {
            system("cls");
            std::cin.clear();
            admin.logInSystem(dr, ndr, pr, cr);
            return;
        }
    }
    else if (role == 2)
    {
        Doctor* doctor = dr.findAccountByLogin(login);
        if (doctor->getFullName().surname == "_")
            doctor = ndr.findAccountByLogin(login);

        if (doctor->loginAndPasswordCorrect(login, password))
        {
            if (doctor->getAccess())
            {
                system("cls");
                std::cin.clear();
                doctor->logInSystem(pr);
                return;
            }
            else
            {
                std::cout << "\nВам отказано в доступе! Дождитесь верификации.\n\n";
                return;
            }
        }
    }
    else if (role == 3)
    {
        Patient* patient = pr.findAccountByLogin(login);
        if (patient->loginAndPasswordCorrect(login, password))
        {
            if (patient->getAccess())
            {
                system("cls");
                std::cin.clear();
                patient->logInSystem(cr, pr);
                return;
            }
            else
            {
                std::cout << "\nВам отказано в доступе! Дождитесь верификации.\n\n";
                return;
            }
        }
    }

    std::cout << "\nВведен неверный логин или пароль!\n\n";
    return;
}

Doctor createDoctorFromConsole()
{
    string encryptedPassword = chps::getCorrectEncryptedPassword(std::cin);

    std::cout << "Введите полное имя\n";

    FullName fullName;
    
    fullName.surname = chps::getCorrectWordInput(std::cin, "Фамилия: ");
    fullName.name = chps::getCorrectWordInput(std::cin, "Имя: ");
    fullName.patronymic = chps::getCorrectWordInput(std::cin, "Отчество: ");

    std::cout << "Введите дату рождения (дд.мм.гггг)\n";

    Date dateOfBirth = chps::getCorrectDateOfBirth(std::cin, 2);

    std::cout << "Введите адрес проживания\n";

    Address address;
    address.city = chps::getCorrectWordInput(std::cin, "Город: ");
    address.street = chps::getCorrectStringInput(std::cin, "Улица: ");
    address.houseNumber = chps::getCorrectPositiveInteger(std::cin, "Номер дома: ");
    address.flatNumber = chps::getCorrectFlatNumber(std::cin);

    string position;
    std::cout << "Введите информацию о квалификации\n";
    position = chps::getCorrectStringInput(std::cin, "Должность: ");

    return Doctor(encryptedPassword, 2, fullName, dateOfBirth, address, position);
}

Patient createPatientFromConsole()
{
    string encryptedPassword = chps::getCorrectEncryptedPassword(std::cin);

    std::cout << "Введите полное имя\n";

    FullName fullName;
    
    fullName.surname = chps::getCorrectWordInput(std::cin, "Фамилия: ");
    fullName.name = chps::getCorrectWordInput(std::cin, "Имя: ");
    fullName.patronymic = chps::getCorrectWordInput(std::cin, "Отчество: ");

    std::cout << "Введите дату рождения (дд.мм.гггг)\n";

    Date dateOfBirth = chps::getCorrectDateOfBirth(std::cin, 3);

    std::cout << "Введите адрес проживания\n";

    Address address;
    address.city = chps::getCorrectWordInput(std::cin, "Город: ");
    address.street = chps::getCorrectStringInput(std::cin, "Улица: ");
    address.houseNumber = chps::getCorrectPositiveInteger(std::cin, "Номер дома: ");
    address.flatNumber = chps::getCorrectFlatNumber(std::cin);

    return Patient(encryptedPassword, 3, fullName, dateOfBirth, address);
}

void registerInSystem(AccountRepository<Doctor>& ndr, AccountRepository<Patient>& pr)
{
    std::cout << "\nКакой аккаунт вы хотите создать? Выберите соответствующее число.\n"
        "1 - доктор;\n"
        "2 - пациент;\n"
        "3 - выйти в главное меню.\n\n";

    int choice = chps::getCorrectMenuInput(3);
    system("cls");

    switch (choice)
    {
    case 1:
    {
        Doctor newDoctor(createDoctorFromConsole());
        ndr.addNewAccount(newDoctor);
        std::cout << "Ваш логин: " << newDoctor.getLogin() << std::endl;
        break;
    }
    case 2:
    {
        Patient newPatient(createPatientFromConsole());
        pr.addNewAccount(newPatient);
        std::cout << "Ваш логин: " << newPatient.getLogin() << std::endl;
        break;
    }
    case 3:
        return;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    AccountRepository<Doctor> dr("doctors_file.txt");
    AccountRepository<Doctor> ndr("not_verified_doctors_file.txt");
    AccountRepository<Patient> pr("patient_file.txt");

    ClinicRepository cr;
    Administrator admin;

    while (true)
    {
        std::cout << "Что вы хотите сделать? Выберите соответствующее число.\n"
            "1 - войти в систему;\n"
            "2 - зарегистрироваться в системе;\n"
            "3 - выйти из системы.\n\n";

        int choice = chps::getCorrectMenuInput(3);
        system("cls");
        switch (choice)
        {
        case 1: (logInSystem(dr, ndr, pr, cr)); break;
        case 2: 
            registerInSystem(ndr, pr);
            chps::endCase();
            break;
        case 3: return 0;
        }
        
    }
}
