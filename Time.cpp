#include "Time.h"

void Time::setCurrentTime()
{
    struct tm localtime;
    time_t now = time(NULL);
    localtime_s(&localtime, &now);
    hour = localtime.tm_hour;
    minute = localtime.tm_min;
    second = localtime.tm_sec;
}

Time::Time()
{
    hour = 0;
    minute = 0;
    second = 0;
}

Time::Time(int hour, int minute)
{
    this->hour = hour;
    this->minute = minute;
    second = 0;
}

string Time::getStringForFile()
{
    return std::to_string(hour) + " " + std::to_string(minute) + " " + std::to_string(second);
}

string Time::getStringForLogin()
{
    string stringForLogin = "";
    hour < 10 ? stringForLogin += "0" + std::to_string(hour) : stringForLogin += std::to_string(hour);
    minute < 10 ? stringForLogin += "0" + std::to_string(minute) : stringForLogin += std::to_string(minute);
    second < 10 ? stringForLogin += "0" + std::to_string(second) : stringForLogin += std::to_string(second);

    return stringForLogin;
}

std::ostream& operator<<(std::ostream& os, const Time& time)
{
    time.hour < 10 ? os << "0" << time.hour << ":" : os << time.hour << ":";
    time.minute < 10 ? os << "0" << time.minute << ":" : os << time.minute << ":";
    time.second < 10 ? os << "0" << time.second : os << time.second;

    return os;
}

std::istream& operator>>(std::istream& in, Time& time)
{
    return in >> time.hour >> time.minute >> time.second;
}
