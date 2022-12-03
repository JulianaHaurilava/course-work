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
    return std::to_string(hour) + std::to_string(minute) + std::to_string(second);
}

std::ostream& operator<<(std::ostream& os, const Time& time)
{
    return os << time.hour << ":" << time.minute << ":" << time.second;
}
