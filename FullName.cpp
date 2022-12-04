#include "FullName.h"

std::ostream& operator<<(std::ostream& os, const FullName& fullName)
{
    return os << fullName.surname << " " << fullName.name << " " << fullName.patronymic;
}

bool operator==(const FullName& fullName_1, const FullName& fullName_2)
{
    return fullName_1.surname == fullName_2.surname &&
        fullName_1.name == fullName_2.name &&
        fullName_1.patronymic == fullName_2.patronymic;
}

bool operator!=(const FullName& fullName_1, const FullName& fullName_2)
{
    return !(fullName_1.surname == fullName_2.surname &&
        fullName_1.name == fullName_2.name &&
        fullName_1.patronymic == fullName_2.patronymic);
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
