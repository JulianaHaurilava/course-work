#include "ClinicRepository.h"
#include "Administrator.h"
#include "Checkups.h"
#include "AccountRepository.h"

#include <iostream>
#include <windows.h>

bool logInSystem(AccountRepository<Doctor>& dr, AccountRepository<Doctor>& ndr,
    AccountRepository<Patient>& pr, ClinicRepository& cr)
{
    string login, password;

    std::cout << "Введите логин: ";
    std::cin >> login;
    int role = getRole(login);

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
            admin.logInSystem(dr, ndr, pr, cr);
            return true;
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
                doctor->logInSystem(pr);
                return true;
            }
            else
            {
                std::cout << "\nВам отказано в доступе! Дождитесь верификации.\n\n";
                return false;
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
                patient->logInSystem(cr);
                return true;
            }
            else
            {
                std::cout << "\nВам отказано в доступе! Дождитесь верификации.\n\n";
                return false;
            }
        }
    }

    std::cout << "\nВведен неверный логин или пароль!\n\n";
    return false;
}

Doctor createDoctorFromConsole()
{
    string encryptedPassword = getCorrectEncryptedPassword(std::cin);

    std::cout << "Введите полное имя\n";

    FullName fullName;
    
    fullName.surname = getCorrectWordInput(std::cin, "Фамилия: ");
    fullName.name = getCorrectWordInput(std::cin, "Имя: ");
    fullName.patronymic = getCorrectWordInput(std::cin, "Отчество: ");

    std::cout << "Введите дату рождения (дд.мм.гггг)\n";

    Date dateOfBirth = getCorrectDateOfBirth(std::cin, 2);

    std::cout << "Введите адрес проживания\n";

    Address address;
    address.city = getCorrectWordInput(std::cin, "Город: ");
    address.street = getCorrectStringInput(std::cin, "Улица: ");
    address.houseNumber = getCorrectPositiveInteger(std::cin, "Номер дома: ");
    address.flatNumber = getCorrectFlatNumber(std::cin);

    string position;
    std::cout << "Введите информацию о квалификации\n";
    position = getCorrectStringInput(std::cin, "Должность: ");

    return Doctor(encryptedPassword, 2, fullName, dateOfBirth, address, position);
}

Patient createPatientFromConsole()
{
    string encryptedPassword = getCorrectEncryptedPassword(std::cin);

    std::cout << "Введите полное имя\n";

    FullName fullName;
    
    fullName.surname = getCorrectWordInput(std::cin, "Фамилия: ");
    fullName.name = getCorrectWordInput(std::cin, "Имя: ");
    fullName.patronymic = getCorrectWordInput(std::cin, "Отчество: ");

    std::cout << "Введите дату рождения (дд.мм.гггг)\n";

    Date dateOfBirth = getCorrectDateOfBirth(std::cin, 3);

    std::cout << "Введите адрес проживания\n";

    Address address;
    address.city = getCorrectWordInput(std::cin, "Город: ");
    address.street = getCorrectStringInput(std::cin, "Улица: ");
    address.houseNumber = getCorrectPositiveInteger(std::cin, "Номер дома: ");
    address.flatNumber = getCorrectFlatNumber(std::cin);

    return Patient(encryptedPassword, 3, fullName, dateOfBirth, address);
}

void registerInSystem(AccountRepository<Doctor>& ndr, AccountRepository<Patient>& pr)
{
    std::cout << "\nКакой аккаунт вы хотите создать? Выберите соответствующее число.\n"
        "1 - доктор;\n"
        "2 - пациент;\n"
        "3 - выйти в главное меню.\n\n";

    int choice = getCorrectMenuInput(3);
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

    AccountRepository<Doctor> dr("doctors_file");
    AccountRepository<Doctor> ndr("not_verified_doctors_file");
    AccountRepository<Patient> pr("patient_file");

    ClinicRepository cr;
    Administrator admin;

    while (true)
    {
        std::cout << "\nЧто вы хотите сделать? Выберите соответствующее число.\n"
            "1 - войти в систему;\n"
            "2 - зарегистрироваться в системе;\n"
            "3 - выйти из системы.\n\n";

        int choice = getCorrectMenuInput(3);
        switch (choice)
        {
        case 1:
            if (logInSystem(dr, ndr, pr, cr))
                return 0;
            break;
        case 2: registerInSystem(ndr, pr); break;
        case 3: return 0;
        }
        endCase();
    }
}
