#include "FullName.h"

std::ostream& operator<<(std::ostream& os, const FullName& fullName)
{
    return os << fullName.name << " " << fullName.surname << " " << fullName.patronymic;
}

FullName::FullName()
{
    name = "_";
    surname = "_";
    patronymic = "_";
}

string FullName::getStringForFile()
{
    return name + " " + surname + " " + patronymic;
}
