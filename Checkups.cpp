#pragma once
#include "Checkups.h"

namespace chps
{
    string getCorrectLogin(std::istream& s, const char* message)
    {
        string adminInput;
        while (true)
        {
            try
            {
                std::cout << message;
                getline(std::cin, adminInput);

                if (adminInput.length() == 0) return adminInput;
                int role = stoi(adminInput.substr(0, 2));
                if (adminInput.length() != 16 ||
                    !(role == 2 || role == 3))
                    throw - 1;

                return adminInput;
            }
            catch (std::invalid_argument)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Введен неверный логин.\n" <<
                    "Повторите ввод.\n\n";
            }
            catch (int)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Введен неверный логин.\n" <<
                    "Повторите ввод.\n\n";
            }
        }
    }

    int countAge(int day, int month, int year)
    {
        Date todaysDate;
        todaysDate.setCurrentDate();
        int age = todaysDate.year - year;
        if (todaysDate.month < month || (todaysDate.month == month && todaysDate.day < day))
        {
            age--;
        }
        return age;
    }

    std::string getCorrectStringInput(std::istream& s, const char* message)
    {
        std::string userInput;
        while (true)
        {
            try
            {
                std::cout << message;
                getline(std::cin, userInput);

                if (userInput == "") throw "Пустая строка";
                for (char c : userInput)
                {
                    bool isAlpha = false;
                    for (char c_c : RUS_LETTERS)
                    {
                        if (c == c_c)
                        {
                            isAlpha = true;
                        }
                    }
                    if (!isAlpha && c != ' ' && c != '-')
                    {
                        throw - 1;
                    }
                }
                return userInput;
            }
            catch (const char*)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Введена пустая строка.\n" <<
                    "Повторите ввод.\n\n";
            }
            catch (int)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! В строке содержатся недопустимые символы.\n" <<
                    "Повторите ввод.\n\n";
            }
            catch (std::out_of_range)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Ввод превышает допустимые размеры.\n" <<
                    "Повторите ввод.\n\n";
            }
        }
    }

    std::string getCorrectStringInputEsc(std::istream& s, const char* message)
    {
        std::string userInput;
        while (true)
        {
            try
            {
                std::cout << message;
                getline(std::cin, userInput);

                for (char c : userInput)
                {
                    bool isAlpha = false;
                    for (char c_c : RUS_LETTERS)
                    {
                        if (c == c_c)
                        {
                            isAlpha = true;
                        }
                    }
                    if (!isAlpha && c != ' ' && c != '-')
                    {
                        throw - 1;
                    }
                }
                return userInput;
            }
            catch (int)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! В строке содержатся не только буквы.\n" <<
                    "Повторите ввод.\n\n";
            }
            catch (std::out_of_range)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Ввод превышает допустимые размеры.\n" <<
                    "Повторите ввод.\n\n";
            }
        }
    }

    std::string getCorrectWordInput(std::istream& s, const char* message)
    {
        std::string userInput;
        while (true)
        {
            try
            {
                std::cout << message;
                getline(std::cin, userInput);

                if (userInput == "") throw "Пустая строка";
                for (char c : userInput)
                {
                    bool isAlpha = false;
                    for (char c_c : RUS_LETTERS)
                    {
                        if (c == c_c)
                        {
                            isAlpha = true;
                        }
                    }
                    if (!isAlpha)
                    {
                        throw - 1;
                    }
                }
                return userInput;
            }
            catch (const char*)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Введена пустая строка.\n" <<
                    "Повторите ввод.\n\n";
            }
            catch (int)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! В строке содержатся не только буквы.\n" <<
                    "Повторите ввод.\n\n";
            }
            catch (std::out_of_range)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Ввод превышает допустимые размеры.\n" <<
                    "Повторите ввод.\n\n";
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
                std::cin.clear();
                do
                {
                    getline(std::cin, userInput);
                } while (userInput.empty());

                for (char c : userInput)
                {
                    if (!iswdigit(c))
                        throw std::invalid_argument("Ввод содержит недопустимые символы.");
                }
                checkIfInteger(userInput);

                int userIntInput = stoi(userInput);

                if (userIntInput <= 0) throw - 1;
                return userIntInput;
            }
            catch (const char*)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Ввведенное число не является целым.\n" <<
                    "Повторите ввод.\n\n";
            }
            catch (std::invalid_argument)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Ввод содержит недопустимые символы.\n" <<
                    "Повторите ввод.\n\n";
            }
            catch (int)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Введенное число не положительное.\n" <<
                    "Повторите ввод.\n\n";
            }
            catch (std::out_of_range)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Ввод превышает допустимые размеры.\n" <<
                    "Повторите ввод.\n\n";
            }
        }
    }

    int getCorrectMenuInput(int numberOfMenuItem)
    {
        int userInput;
        while (true)
        {
            userInput = getCorrectPositiveInteger(std::cin, "");
            if (userInput < 1 || userInput > numberOfMenuItem)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Необходимо ввести число от 1 до " <<
                    numberOfMenuItem << std::endl << "Повторите ввод.\n\n";
                continue;

            }
            return userInput;

        }
    }

    double getCorrectPositiveDouble(std::istream& s, const char* message)
    {
        std::string userInput;
        while (true)
        {
            try
            {
                std::cout << message;
                getline(std::cin, userInput);

                for (char c : userInput)
                {
                    if (!iswdigit(c))
                        if (c != '.')
                            throw std::invalid_argument("Ввод содержит недопустимые символы.");
                }

                double userDoubleInput = stod(userInput);

                if (userDoubleInput <= 0) throw - 1;
                return userDoubleInput;
            }
            catch (std::invalid_argument)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Ввод содержит недопустимые символы.\n" <<
                    "Повторите ввод.\n\n";
            }
            catch (int)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Введенное число не положительное.\n" <<
                    "Повторите ввод.\n\n";
            }
            catch (std::out_of_range)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Ввод превышает допустимые размеры.\n" <<
                    "Повторите ввод.\n\n";
            }
        }
    }


    void checkDay(int day, int month, int year)
    {
        try
        {
            if (!(year % 4 == 0 && month == 2))
            {
                if (day < 1 || day > daysForMonths[month - 1])\
                {
                    throw std::range_error("Введен некорректный день.");
                }
            }

            else
            {
                if (day < 1 || day > 29)
                {
                    throw std::range_error("Введен некорректный день.");
                }
            }

        }
        catch (const std::exception& e)
        {
            throw std::range_error("Введен некорректный день.");
        }
    }

    void checkMonth(int month)
    {
        try
        {
            if (month < 1 || month > 12)
                throw std::range_error("Месяц не может быть меньше 1 и больше 12.");
        }
        catch (const std::exception& e)
        {
            throw std::range_error("Месяц не может быть меньше 1 и больше 12.");
        }
    }

    void checkDoctorAge(int day, int month, int year)
    {
        int age = countAge(day, month, year);
        try
        {
            if (age < 18 || age > 65)
                throw std::range_error("Сотрудник не может быть младше 18 или страше 65 лет.");
        }
        catch (const std::range_error& e)
        {
            throw std::range_error("Сотрудник не может быть младше 18 или страше 65 лет.");
        }

    }

    void checkPatientAge(int day, int month, int year)
    {
        int age = countAge(day, month, year);
        try
        {
            if (age < 18 || age > 120)
                throw std::range_error("Пациент не может быть старше младше 18 или старше 120 лет.");
        }
        catch (const std::range_error& e)
        {
            throw std::range_error("Пациент не может быть старше младше 18 или старше 120 лет.");
        }
    }

    Date getCorrectDateOfBirth(std::istream& s, int role)
    {
        std::string userInput;
        while (true)
        {
            try
            {
                std::cout << "Дата рождения: ";
                getline(std::cin, userInput);

                int day = stoi(userInput.substr(0, 2));
                int month = stoi(userInput.substr(3, 2));
                int year = stoi(userInput.substr(6));

                checkMonth(month);
                checkDay(day, month, year);
                if (role == 2)
                {
                    checkDoctorAge(day, month, year);
                }
                else checkPatientAge(day, month, year);

                return Date(day, month, year);
            }
            catch (std::invalid_argument)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Ввод содержит недопустимые символы.\n" <<
                    "Повторите ввод.\n\n";
            }
            catch (const std::range_error& e)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! " << e.what() << "\nПовторите ввод.\n\n";
            }
            catch (std::out_of_range)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Ввод превышает допустимые размеры.\n" <<
                    "Повторите ввод.\n\n";
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

    int getCorrectFlatNumber(std::istream& s)
    {
        std::cout << "Есть квартира? Выберите соответствующее число.\n"
            "1 - да;\n"
            "2 - нет;\n\n";

        int choice = getCorrectMenuInput(2);

        if (choice == 1)
            return getCorrectPositiveInteger(std::cin, "Номер квартиры: ");

        return 0;
    }

    string getCorrectEncryptedPassword(std::istream& s)
    {
        std::string userInput;
        std::cout << "Требования к паролю:\n" <<
            "Минимальная длина - 8 символов. Пароль должен содержать:\n" <<
            "1. Заглавную латинскую букву;\n" <<
            "2. Маленькую латинскую букву;\n" <<
            "3. Цифру;\n" <<
            "4. Специальный символ.\n\n";
        while (true)
        {
            try
            {
                std::cout << "Придумайте новый пароль: ";
                getline(std::cin, userInput);

                if (userInput.length() < 8)
                {
                    throw InvalidPasswordExeption("Длина пароля должна быть не меньше 8 символов.");
                }

                int upperAlphaCounter = 0, lowerAlphaCounter = 0,
                    digitCounter = 0, specialSymbolCounter = 0;
                for (char c : userInput)
                {
                    if (c == 32)
                    {
                        throw InvalidPasswordExeption("Пароль не может содержать пробел.");
                    }
                    if (c < 0 || c > 255)
                    {
                        throw InvalidPasswordExeption("Пароль содержит недопустимые символы.");
                    }
                    if (isalpha(c))
                    {
                        if (isupper(c))
                        {
                            upperAlphaCounter++;
                        }
                        else lowerAlphaCounter++;
                    }
                    else if (isdigit(c))
                    {
                        digitCounter++;
                    }
                    else specialSymbolCounter++;
                }

                if (!(upperAlphaCounter + lowerAlphaCounter))
                    throw InvalidPasswordExeption("В вашем пароле нет букв!");
                else if (!upperAlphaCounter)
                    throw InvalidPasswordExeption("В вашем пароле нет букв верхнего регистра!");
                else if (!lowerAlphaCounter)
                    throw InvalidPasswordExeption("В вашем пароле нет букв нижнего регистра!");
                else if (!digitCounter)
                    throw InvalidPasswordExeption("В вашем пароле нет цифр!");
                else if (!specialSymbolCounter)
                    throw InvalidPasswordExeption("В вашем пароле нет специальных символов!");


                Hash h;

                string encryptedPassword = h.getHash(userInput, 6);
                return encryptedPassword;
            }
            catch (const InvalidPasswordExeption& e)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! " << e.what() << "\nПовторите ввод.\n\n";
            }
            catch (std::out_of_range)
            {
                std::cin.clear();
                std::cout << "Введенные данные некорректны! Ввод превышает допустимые размеры.\n" <<
                    "Повторите ввод.\n\n";
            }
        }
    }

    void endCase()
    {
        std::cout << "\nДля того, чтобы продолжить, нажмите любую клавишу...";
        _getch();
        system("cls");
        std::cin.clear();
    }
}