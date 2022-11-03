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
        //Минимальная строка хеша, кратная двум;
        int minlen = 2;
        //Длинна строки, ближайшая к нужной длине хеша
        int realMinlen = 0;

        //Получение хеша с помощью метода getSault(userString);
        int originalSault = this->getSault(userString);
        //Получение длины строки
        int originalStringLength = userString.size();

        //Получение длины строки, ближайшей к желаемой длине и кратной 2
        while (minlen <= length)
        {
            realMinlen = minlen *= 2;
        }
        //Получение ближайшее к длине исходной строки число типа 2^n
        while (minlen < originalStringLength)
        {
            minlen *= 2;
        }

        //Определение количества недостающих элементов
        int addCount = minlen - originalStringLength;
        //Добавление
        for (int i = 0; i < addCount; i++)
        {
            userString += this->recieveCode(userString[i] + userString[i + 1]);
        }

        //Определение максимальной соли
        int maxSault = this->getSault(userString);
        int maxStringLength = userString.size();

        //Определение степени сжатия строки до ближайшего значения
        while (userString.size() != realMinlen)
        {
            for (int i = 0, stringMid = userString.size() / 2; i < stringMid; i++)
            {
                this->hash += this->recieveCode(userString[stringMid + i] + userString[stringMid - i]);
            }
            userString = this->hash;
            this->hash.clear();
        }

        //Приведение к нужной длине
        int symbolsToRemoveAmount = realMinlen - length;
        for (int i = 0, countCompress = realMinlen / symbolsToRemoveAmount;
            this->hash.size() < (length - 4); i++)
        {
            if (i % countCompress == 0)
            {
                this->hash += this->recieveCode(userString[i] + userString[++i]);
            }
            else this->hash += userString[i];
        }

        //Добавление оставшейся соли
        this->hash += this->recieveCode(originalSault);
        this->hash += this->recieveCode(originalStringLength);
        this->hash += this->recieveCode(maxSault);
        this->hash += this->recieveCode(maxStringLength);

        return this->hash;
    }
    return "";
}
