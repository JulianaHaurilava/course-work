#include "Account.h"

string Account::getStringForFile()
{
    return login + " " + encryptedPassword + " " + std::to_string(role);
}
