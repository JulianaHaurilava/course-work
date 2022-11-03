#pragma once
#pragma once

#include <iostream>

using std::string;

class Hash
{
    string hash;

    /// <summary>
    /// Возвращает контрольную сумма элементов, приводит каждый элемент к кодировке ANSI
    /// </summary>
    /// <param name="element"></param>
    /// <returns></returns>
    int recieveCode(int element);

    /// <summary>
    /// Получает сумму кодов всех символов, находящихся в строке
    /// </summary>
    /// <param name="passwordString"></param>
    /// <returns></returns>
    int getSault(string userString);

public:

    /// <summary>
    /// Получает хэш определённой длины
    /// </summary>
    /// <param name="userString"> - пароль</param>
    /// <param name="length"> - длина хеша</param>
    /// <returns></returns>
    string getHash(string userString, int length);
};
