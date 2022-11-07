#include "Repository.h"
#include "Administrator.h"

#include <iostream>
#include <windows.h>

//ошибки еще нужно доработать, но это пока не горит
std::string getCorrectStingInput(std::istream& s, const char* message)
{
    std::string userInput;
    while (true)
    {
        try
        {
            std::cout << message;
            std::cin.unsetf(std::ios::skipws);
            std::cin >> userInput;


            if (!std::cin.good()) throw "Пробел";
            std::cin.ignore(32767, '\n');
            std::cin.setf(std::ios::skipws);
            return userInput;
        }
        catch (const char*)
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Введенные данные некорректны!\n";
        }
    }
}

void checkIfInteger(std::string userInput)
{
    try
    {
        if (userInput.find('.') != -1 || userInput.find(',') != -1)
            throw "Число не целое!";
    }
    catch (const char*)
    {
        throw "Число не целое!";
    }
}

int getCorrectPositiveInteger(std::istream& s, const char* message)
{
    std::string userInput;
    while (true)
    {
        try
        {
            std::cout << message;
            std::cin.unsetf(std::ios::skipws);
            std::cin >> userInput;
            checkIfInteger(userInput);

            int userIntInput = stoi(userInput);

            if (userIntInput <= 0) throw 1;
            std::cin.ignore(32767, '\n');
            std::cin.setf(std::ios::skipws);
            return userIntInput;
        }
        catch (const char*)
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Введенные данные некорректны. Число не целое!\n";
        }
        catch (std::invalid_argument)
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Введенные данные некорректны. Повторите ввод.\n";
        }
        catch (int)
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Введенное число не положительное. Повторите ввод.\n";
        }
    }
}

int getCorrectMenuInput(int numberOfMenuItem)
{
    int userInput;
    while (true)
    {
        try
        {
            std::cin.unsetf(std::ios::skipws);
            std::cin >> userInput;
            if (!userInput) throw false;
            if (userInput < 1 || userInput > numberOfMenuItem) throw 'a';
            std::cin.ignore(32767, '\n');
            std::cin.setf(std::ios::skipws);

            return userInput;
        }
        catch (char)
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Ввод некорректен. Необходимо ввести число от 1 до " << numberOfMenuItem << std::endl;
        }

        catch (bool)
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Введенные данные некорректны. Повторите ввод.\n";
        }
    }

    return userInput;
}

double getCorrectPositiveDouble(std::istream& s, const char* message)
{
    double userInput;
    while (true)
    {
        try
        {
            std::cout << message;
            std::cin.unsetf(std::ios::skipws);
            std::cin >> userInput;
            if (!std::cin.good()) throw "Некорректный ввод!";
            if (userInput <= 0) throw 1;
            std::cin.ignore(32767, '\n');
            std::cin.setf(std::ios::skipws);
            return userInput;
        }
        catch (const char[])
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Некорректный ввод. Повторите ввод.\n";
        }
        catch (int)
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Введенное число не положительное. Повторите ввод.\n";
        }
    }
}

int getRole(string login)
{
    int role;
    try
    {
        role = stoi(login.substr(0, 2));
    }
    catch (std::invalid_argument)
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        return -1;
    }
    return role;
}

void endCase()
{
    std::cout << "Для того, чтобы продолжить, нажмите любую клавишу...";
    _getch();
    system("cls");
}


bool logInSystem(Repository r)
{
    string login, password;

    std::cout << "Введите логин: ";
    std::cin >> login;
    int role = getRole(login);

    std::cout << "Введите пароль: ";
    std::cin >> password;


    if (role == 1)
    {
        Administrator admin;
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

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Repository r;

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
            if (logInSystem(r))
                return 0;
            break;
        case 2: /*registerInSystem(users);*/ break;
        case 3: return 0;
        }
        endCase();
    }
}
