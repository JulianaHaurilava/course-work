#include "User.h"

string User::getStringForFile()
{

    return login + " " + encryptedPassword + " " + std::to_string(access);

}
