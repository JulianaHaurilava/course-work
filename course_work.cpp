#include "Repository.h"
#include "Administrator.h"
#include "Checkups.h"

#include <iostream>
#include <windows.h>

//ошибки еще нужно доработать, но это пока не горит


void endCase()
{
    std::cout << "Для того, чтобы продолжить, нажмите любую клавишу...";
    _getch();
    system("cls");
}

bool logInSystem(Repository r, Administrator admin)
{
    string login, password;

    std::cout << "Введите логин: ";
    std::cin >> login;
    int role = getRole(login);

    std::cout << "Введите пароль: ";
    std::cin >> password;


    if (role == 1)
    {
        if (admin.loginAndPasswordCorrect(login, password))
        {
            admin.logInSystem();
        }
    }
    else if (role == 2)
    {
        Doctor doctor = r.findDoctorByLogin(login);
        if (doctor.loginAndPasswordCorrect(login, password))
        {
            if (doctor.getAccess())
            {
                doctor.logInSystem();
            }
            else
            {
                std::cout << "Вам отказано в доступе! Дождитесь верификации.\n\n";
                return false;
            }
        }
    }
    else if (role == 3)
    {
        Patient patient = r.findPatientByLogin(login);
        if (patient.loginAndPasswordCorrect(login, password))
        {
            if (patient.getAccess())
            {
                patient.logInSystem();
            }
            else
            {
                std::cout << "Вам отказано в доступе! Дождитесь верификации.\n\n";
                return false;
            }
        }
    }

    std::cout << "Введен неверный логин или пароль!\n\n";
    return false;
}

Doctor createDoctorFromConsole()
{
    string encryptedPassword = getCorrectEncryptedPassword(std::cin);

    std::cout << "Введите полное имя\n";

    FullName fullName;
    fullName.name = getCorrectStingInput(std::cin, "Имя: ");
    fullName.surname = getCorrectStingInput(std::cin, "Фамилия: ");
    fullName.patronymic = getCorrectStingInput(std::cin, "Отчество: ");

    std::cout << "Введите дату рождения\n";

    Date dateOfBirth = getCorrectDateOfBirth(std::cin, 2);

    std::cout << "Введите адрес проживания\n";

    Address address;
    address.city = getCorrectStingInput(std::cin, "Город: ");
    address.street = getCorrectStingInput(std::cin, "Имя: ");
    address.houseNumber = getCorrectPositiveInteger(std::cin, "Номер дома: ");
    address.flatNumber = getCorrectFlatNumber(std::cin);

    std::cout << "Введите информацию о квалификации\n";
    string position = getCorrectStingInput(std::cin, "Должность: ");

    return Doctor(encryptedPassword, 2, fullName, dateOfBirth, address, position);
}

Patient createPatientFromConsole()
{
    string encryptedPassword = getCorrectEncryptedPassword(std::cin);

    std::cout << "Введите полное имя\n";

    FullName fullName;
    fullName.name = getCorrectStingInput(std::cin, "Имя: ");
    fullName.surname = getCorrectStingInput(std::cin, "Фамилия: ");
    fullName.patronymic = getCorrectStingInput(std::cin, "Отчество: ");

    std::cout << "Введите дату рождения\n";

    Date dateOfBirth = getCorrectDateOfBirth(std::cin, 2);

    std::cout << "Введите адрес проживания\n";

    Address address;
    address.city = getCorrectStingInput(std::cin, "Город: ");
    address.street = getCorrectStingInput(std::cin, "Имя: ");
    address.houseNumber = getCorrectPositiveInteger(std::cin, "Номер дома: ");
    address.flatNumber = getCorrectFlatNumber(std::cin);

    return Patient(encryptedPassword, 2, fullName, dateOfBirth, address);
}

void registerInSystem(Repository r, Administrator admin)
{
    std::cout << "\nКакой аккаунт вы хотите создать? Выберите соответствующее число.\n"
        "1 - доктор;\n"
        "2 - пациент;\n"
        "3 - выйти в главное меню.\n\n";

    int choice = getCorrectMenuInput(3);

    if (choice == 1)
    {
        Doctor newDoctor(createDoctorFromConsole());
        admin.addNewDoctor(newDoctor);
    }
    else if (choice == 2)
    {
        Patient newPatient(createPatientFromConsole());
        admin.addNewPatient(newPatient);
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Repository r;
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
            if (logInSystem(r, admin))
                return 0;
            break;
        case 2: /*registerInSystem(users);*/ break;
        case 3: return 0;
        }
        endCase();
    }
}
