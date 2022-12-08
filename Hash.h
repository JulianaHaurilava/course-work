#pragma once
#pragma once

#include <iostream>

using std::string;

class Hash
{
    static int counter;
    string hash;

    /// <summary>
    /// Возвращает контрольную сумма элементов, приводит каждый элемент к кодировке ANSI
    /// </summary>
    /// <param name="element"></param>
    /// <returns></returns>
    static int recieveCode(int element);

    /// <summary>
    /// Получает сумму кодов всех символов, находящихся в строке
    /// </summary>
    /// <param name="passwordString"></param>
    /// <returns></returns>
    static int getSault(string userString);

public:

    /// <summary>
    /// Получает хэш определённой длины
    /// </summary>
    /// <param name="userString"> - пароль</param>
    /// <param name="length"> - длина хеша</param>
    /// <returns></returns>
    string getHash(string userString, int length);
};
