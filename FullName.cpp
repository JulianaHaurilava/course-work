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
    return surname + " " + name + " " + patronymic;
}

std::istream& operator>>(std::istream& in, FullName& fullName)
{
    return in >> fullName.surname >> fullName.name >> fullName.patronymic;
}
