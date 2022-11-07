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
            for (char c : userInput)
            {
                if (!isalpha(c))
                {
                    throw 1;
                }
            }
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
        catch (int)
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

//свой класс ісключеній (напісать)
int getCorrectYear(std::istream& s, const char* message)
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

            if (userIntInput > 2004 || userIntInput < 1957) throw 1;
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
            std::cout << "Сотрудники клиники не могут быть младше 18 и старше 65 лет. Повторите ввод.\n";
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

Doctor CreateDoctorFromConsole()
{
    string encryptedPassword = getCorrectEncryptedPassword(std::cin, "Придумайте новый пароль: "); //танцы с паролем, да....

    std::cout << "Введите полное имя врача\n";

    FullName fullName;
    fullName.name = getCorrectStingInput(std::cin, "Имя: ");
    fullName.surname = getCorrectStingInput(std::cin, "Фамилия: ");
    fullName.patronymic = getCorrectStingInput(std::cin, "Отчество: ");

    std::cout << "Введите дату рождения\n";

    Date dateOfBirth = getCorrectDateOfBirth(std::cin, "Дата рождения: ");

    std::cout << "Введите адрес проживания\n";

    Address address;
    address.city = getCorrectStingInput(std::cin, "Город: ");
    address.street = getCorrectStingInput(std::cin, "Имя: ");
    address.houseNumber = getCorrectPositiveInteger(std::cin, "Номер дома: ");
    address.flatNumber = getCorrectFlatNumber(std::cin, "Номер квартиры: "); //здесь указать, что можно ввести _

    std::cout << "Введите информацию о квалификации врача\n";
    string position = getCorrectStingInput(std::cin, "Должность: ");

    return Doctor(encryptedPassword, 2, fullName, dateOfBirth, address, position);
}

bool registerInSystem(Repository r)
{
    std::cout << "\nКакой аккаунт вы хотите создать? Выберите соответствующее число.\n"
        "1 - доктор;\n"
        "2 - пациент;\n"
        "3 - выйти в главное меню.\n\n";

    int choice = getCorrectMenuInput(3);

    switch (choice)
    {
    case 1:
        Doctor newDoctor(CreateDoctorFromConsole()); // что будетт
        //и добавить в массив к админу :) мне пиздец
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
            if (logInSystem(r))
                return 0;
            break;
        case 2: /*registerInSystem(users);*/ break;
        case 3: return 0;
        }
        endCase();
    }
}
