#include "Account.h"

string Account::getLogin()
{
    return login;
}

string Account::getEncryptedPassword()
{
    return encryptedPassword;
}

string Account::getStringForFile()
{
    return login + " " + encryptedPassword + " " + std::to_string(access);
}

bool Account::checkLoginAndPassword(string login, string password)
{
    Hash h;
    string encryptedPassword = h.getHash(password, 6);
    return this->login == login && this->encryptedPassword == encryptedPassword;
}

string Account::generateLogin(int role)
{
    Date currentDate;
    currentDate.setCurrentDate();

    Time currentTime;
    currentTime.setCurrentTime();

    return "0" + std::to_string(role) + currentDate.getStringForLogin() + currentTime.getStringForLogin();
}

Account::Account()
{
    login = "_";
    encryptedPassword = "_";
    access = false;
}

Account::Account(string encryptedPassword, int role)
{
    this->encryptedPassword = encryptedPassword;
    login = generateLogin(role);
    access = false;
}



