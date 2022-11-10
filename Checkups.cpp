#include "Checkups.h"


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

std::string getCorrectStingInput(std::istream& s, const char* message)
{
    std::string userInput;
    while (true)
    {
        try
        {
            std::cout << message;
            getline(std::cin, userInput);

            if (userInput == "") throw "������ ������";
            for (char c : userInput)
            {
                bool isAlpha = false;
                for (char c_c : letters)
                {
                    if (c == c_c)
                    {
                        isAlpha = true;
                    }
                }
                if (!isAlpha)
                {
                    throw -1;
                }
            }
            return userInput;
        }
        catch (const char*)
        {
            std::cin.clear();
            std::cout << "��������� ������ �����������! ������� ������ ������.\n" <<
                "��������� ����.\n\n";
        }
        catch (int)
        {
            std::cin.clear();
            std::cout << "��������� ������ �����������! � ������ ���������� �� ������ �����.\n" <<
                "��������� ����.\n\n";
        }
    }
}

void checkIfInteger(std::string userInput)
{
    try
    {
        if (userInput.find('.') != -1 || userInput.find(',') != -1)
            throw "����� �� �����!";
    }
    catch (const char*)
    {
        throw "����� �� �����!";
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
            getline(std::cin, userInput);

            for (char c : userInput)
            {
                if (!iswdigit(c)) 
                    throw std::invalid_argument("���� �������� ������������ �������.");
            }
            checkIfInteger(userInput);

            int userIntInput = stoi(userInput);

            if (userIntInput <= 0) throw -1;
            return userIntInput;
        }
        catch (const char*)
        {
            std::cin.clear();
            std::cout << "��������� ������ �����������! ���������� ����� �� �������� �����.\n" <<
                "��������� ����.\n\n";
        }
        catch (std::invalid_argument)
        {
            std::cin.clear();
            std::cout << "��������� ������ �����������! ���� �������� ������������ �������.\n" <<
                "��������� ����.\n\n";
        }
        catch (int)
        {
            std::cin.clear();
            std::cout << "��������� ������ �����������! ��������� ����� �� �������������.\n" <<
                "��������� ����.\n\n";
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
            std::cout << "��������� ������ �����������! ���������� ������ ����� �� 1 �� " << 
                numberOfMenuItem << std::endl << "��������� ����.\n\n";
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
                if (iswdigit(c))
                    throw std::invalid_argument("���� �������� ������������ �������.");
            }

            int userDoubleInput = stod(userInput);

            if (userDoubleInput <= 0) throw - 1;
            return userDoubleInput;
        }
        catch (std::invalid_argument)
        {
            std::cin.clear();
            std::cout << "��������� ������ �����������! ���� �������� ������������ �������.\n" <<
                "��������� ����.\n\n";
        }
        catch (int)
        {
            std::cin.clear();
            std::cout << "��������� ������ �����������! ��������� ����� �� �������������.\n" <<
                "��������� ����.\n\n";
        }
    }
}


void checkDay(int day, int month, int year)
{
    try
    {
        if (year % 4 != 0 && month != 2)
        {
            if (month < 1 || month > daysForMonths[month - 1])\
            {
                throw std::range_error("������ ������������ ����.");
            }
        }
            
        else
        {
            if (month < 1 || month > 29)
            {
                throw std::range_error("������ ������������ ����.");
            }
        }

    }
    catch (const std::exception& e)
    {
        throw std::range_error("������ ������������ ����.");
    }
}

void checkMonth(int month)
{
    try
    {
        if (month < 1 || month > 12)
            throw std::range_error("����� �� ����� ���� ������ 1 � ������ 12.");
    }
    catch (const std::exception& e)
    {
        throw std::range_error("����� �� ����� ���� ������ 1 � ������ 12.");
    }
}

void checkDoctorAge(int day, int month, int year)
{
    int age = countAge(day, month, year);
    try
    {
        if (age < 18 || age > 65)
            throw std::range_error("��������� �� ����� ���� ������ 18 ��� ������ 65 ���.");
    }
    catch (const std::range_error& e)
    {
        throw std::range_error("��������� �� ����� ���� ������ 18 ��� ������ 65 ���.");
    }

}

void checkPatientAge(int day, int month, int year)
{
    int age = countAge(day, month, year);
    try
    {
        if (age < 18 || age > 120)
            throw std::range_error("������� �� ����� ���� ������ ������ 18 ��� ������ 120 ���.");
    }
    catch (const std::range_error& e)
    {
        throw std::range_error("������� �� ����� ���� ������ ������ 18 ��� ������ 120 ���.");
    }
}

Date getCorrectDateOfBirth(std::istream& s, int role)
{
    std::string userInput;
    while (true)
    {
        try
        {
            std::cout << "���� ��������: ";
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
            std::cout << "��������� ������ �����������! ���� �������� ������������ �������.\n" <<
                "��������� ����.\n\n";
        }
        catch (const std::range_error& e)
        {
            std::cin.clear();
            std::cout << "��������� ������ �����������! " << e.what() << "\n��������� ����.\n\n";
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
    std::cout << "���� ��������? �������� ��������������� �����.\n"
        "1 - ��;\n"
        "2 - ���;\n\n";

    int choice = getCorrectMenuInput(2);

    if (choice == 1)
        return getCorrectPositiveInteger(std::cin, "����� ��������: ");

    return 0;
}

string getCorrectEncryptedPassword(std::istream& s)
{
    std::string userInput;
    while (true)
    {
        try
        {
            std::cout << "���������� ����� ������: ";
            getline(std::cin, userInput);

            if (userInput.length() < 8)
            {
                throw InvalidPasswordExeption("����� ������ ������ ���� �� ������ 8 ��������.");
            }

            int upperAlphaCounter = 0, lowerAlphaCounter = 0, 
                digitCounter = 0, specialSymbolCounter = 0;
            for (char c: userInput)
            {
                if (c == 32)
                {
                    throw InvalidPasswordExeption("������ �� ����� ��������� ������.");
                }
                if (c < 0 || c > 255)
                {
                    throw InvalidPasswordExeption("������ �������� ������������ �������.");
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
                throw InvalidPasswordExeption("� ����� ������ ��� ����!");
            else if (!upperAlphaCounter)
                throw InvalidPasswordExeption("� ����� ������ ��� ���� �������� ��������!");
            else if (!lowerAlphaCounter)
                throw InvalidPasswordExeption("� ����� ������ ��� ���� ������� ��������!");
            else if (!digitCounter)
                throw InvalidPasswordExeption("� ����� ������ ��� ����!");
            else if (!specialSymbolCounter)
                throw InvalidPasswordExeption("� ����� ������ ��� ����������� ��������!");


            Hash h;

            string encryptedPassword = h.getHash(userInput, 6);
            return encryptedPassword;
        }
        catch (const InvalidPasswordExeption& e)
        {
            std::cin.clear();
            std::cout << "��������� ������ �����������! " << e.what() << "\n��������� ����.\n\n";
        }
    }
}

