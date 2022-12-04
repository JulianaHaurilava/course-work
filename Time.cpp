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
    return os << time.hour << ":" << time.minute << ":" << time.second;
}
