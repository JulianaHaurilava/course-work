#include "Account.h"

string Account::getLogin()
{
    return login;
}

string Account::getStringForFile()
{
    return login + " " + encryptedPassword + " " + std::to_string(role);
}




void Account::changeAccess()
{
    access = !access;
}
