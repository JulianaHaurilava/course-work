#pragma once
#pragma once

#include <iostream>

using std::string;

class Hash
{
    static int counter;
    string hash;

    /// <summary>
    /// ���������� ����������� ����� ���������, �������� ������ ������� � ��������� ANSI
    /// </summary>
    /// <param name="element"></param>
    /// <returns></returns>
    static int recieveCode(int element);

    /// <summary>
    /// �������� ����� ����� ���� ��������, ����������� � ������
    /// </summary>
    /// <param name="passwordString"></param>
    /// <returns></returns>
    static int getSault(string userString);

public:

    /// <summary>
    /// �������� ��� ����������� �����
    /// </summary>
    /// <param name="userString"> - ������</param>
    /// <param name="length"> - ����� ����</param>
    /// <returns></returns>
    string getHash(string userString, int length);
};
