#include "Hash.h"

int Hash::recieveCode(int element)
{
    element += 256;
    while (!(element <= 57 && element >= 48 ||
        element <= 90 && element >= 65 ||
        element <= 122 && element >= 97))
    {
        if (element < 48)
        {
            element += 24;
        }
        else element -= 47;
    }

    return element;
}

int Hash::getSault(string userString)
{
    int sault = 0, len = 0;

    for (; len < userString.size(); len++)
    {
        sault += int(userString[len]);
    }
    return sault;
}

string Hash::getHash(string userString, int length)
{
    if (length > 3)
    {
        //����������� ������ ����, ������� ����;
        int minlen = 2;
        //������ ������, ��������� � ������ ����� ����
        int realMinlen = 0;

        //��������� ���� � ������� ������ getSault(userString);
        int originalSault = getSault(userString);
        //��������� ����� ������
        int originalStringLength = userString.size();

        //��������� ����� ������, ��������� � �������� ����� � ������� 2
        while (minlen <= length)
        {
            realMinlen = minlen *= 2;
        }
        //��������� ��������� � ����� �������� ������ ����� ���� 2^n
        while (minlen < originalStringLength)
        {
            minlen *= 2;
        }

        //����������� ���������� ����������� ���������
        int addCount = minlen - originalStringLength;
        //����������
        for (int i = 0; i < addCount; i++)
        {
            userString += recieveCode(userString[i] + userString[i + 1]);
        }

        //����������� ������������ ����
        int maxSault = getSault(userString);
        int maxStringLength = userString.size();

        //����������� ������� ������ ������ �� ���������� ��������
        while (userString.size() != realMinlen)
        {
            for (int i = 0, stringMid = userString.size() / 2; i < stringMid; i++)
            {
                hash += recieveCode(userString[stringMid + i] + userString[stringMid - i]);
            }
            userString = hash;
            hash.clear();
        }

        //���������� � ������ �����
        int symbolsToRemoveAmount = realMinlen - length;
        for (int i = 0, countCompress = realMinlen / symbolsToRemoveAmount;
            hash.size() < (length - 4); i++)
        {
            if (i % countCompress == 0)
            {
                hash += recieveCode(userString[i] + userString[++i]);
            }
            else hash += userString[i];
        }

        //���������� ���������� ����
        hash += recieveCode(originalSault);
        hash += recieveCode(originalStringLength);
        hash += recieveCode(maxSault);
        hash += recieveCode(maxStringLength);

        return hash;
    }
    return "";
}
