#include "Repository.h"

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

void endCase()
{
    std::cout << "Для того, чтобы продолжить, нажмите любую клавишу...";
    _getch();
    system("cls");
}

bool logInSystem()
{
    string login, password;

    std::cout << "Введите логин: ";
    std::cin >> login;
    int role = stoi(login.substr(0, 2));

    std::cout << "Введите пароль: ";
    std::cin >> password;

    if (role == 1)
    {

    }
    else if (role == 2)
    {

    }
    else if (role == 3)
    {

    }
    else
    {

    }
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
        {
            int user_number = checkLoginAndPassword(users);
            if (user_number != -1)
            {
                if (users[user_number].returnAccess())
                {
                    if (users[user_number].returnRole())
                    {
                        system("cls");
                        cout << "Добрый день, " << users[user_number].returnLogin() << "!\n\n";
                        inSystemAsAdmin(users, user_number);
                    }
                    else
                    {
                        system("cls");
                        cout << "Добрый день, " << users[user_number].returnLogin() << "!\n\n";
                        inSystemAsUser(users);
                    }

                    return;
                }
                else
                {
                    system("cls");
                    cout << "Вам отказано в доступе! Требуется разрешение администратора.\n";
                }
            }

            break;
        }
        case 2: registerInSystem(users); break;
        case 3: return 0;
        }
        endCase();
    }
}
