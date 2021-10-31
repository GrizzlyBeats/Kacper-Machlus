#include <iostream>
#include "Time.h"
 
 
Time::Time()
{
    hour = 0;
    minute = 0;
    second = 0;
}
 
Time::Time(int a, int b, int c)
{
    this->hour = a;
    this->minute = b;
    this->second = c;
}
 
auto Time :: operator+ (Time const& o) const -> Time
{
    int nHour;
    int nMinute;
    int nSecond;
 
    if (this->hour + o.hour > 23)
        nHour = (this->hour + o.hour) % 24;
    else nHour = this->hour + o.hour;
 
    if (this->minute + o.minute > 59)
    {
        nMinute = (this->minute + o.minute) % 60;
        nHour++;
    }
    else
        nMinute = this->minute + o.minute;
 
    if (this->second + o.second > 59)
    {
        nSecond = (this->second + o.second) % 60;
        nMinute++;
    }
    else
        nSecond = this->second + o.second;
    
    return Time{
        nHour, nMinute, nSecond
    };
}
 
auto Time :: operator- (Time const& o) const -> Time
{
    int nHour;
    int nMinute;
    int nSecond;
 
    if (o.hour > hour)
        nHour = 24 - (o.hour - hour);
    else
        nHour = hour - o.hour;
 
    if (o.minute > minute)
    {
        nMinute = 60 - (o.minute - minute);
        nHour--;
    }
    else
        nMinute = minute - o.minute;
    
    if (o.second > second)
    {
        nSecond = 60 - (o.second - second);
        nMinute--;
    }
    else
        nSecond = second - o.second;
    
    return Time{
        nHour, nMinute, nSecond
    };
}
 
auto Time:: operator< (Time const& o) const -> bool
{
    if (hour < o.hour)
        return true;
    else if (hour > o.hour)
        return false;
    else if (hour == o.hour)
        if (minute < o.minute)
            return true;
        else if (minute > o.minute)
            return false;
        else if (minute == o.minute)
            if (second < o.second)
                return true;
            else return false;
}
 
auto Time:: operator== (Time const& o) const -> bool
{
    return (hour == o.hour && minute == o.minute && second == o.second);
}
 
auto Time:: operator!= (Time const& o) const -> bool
{
    return !(hour == o.hour && minute == o.minute && second == o.second);
}
 
auto Time:: operator> (Time const& o) const -> bool
{
    if (hour > o.hour)
        return true;
    else if (hour < o.hour)
        return false;
    else if (hour == o.hour)
        if (minute > o.minute)
            return true;
        else if (minute < o.minute)
            return false;
        else if (minute == o.minute)
            if (second > o.second)
                return true;
            else return false;
}
 
auto Time::count_seconds() const->uint64_t
{
    return ((this->hour * 60) + this->minute) * 60 + this->second;
}
 
auto Time::count_minutes() const->uint64_t
{
    return (this->hour * 60) + this->minute;
}
 
auto Time::time_to_midnight() const->Time
{
    Time time (this->hour, this->minute, this->second);
    Time midnight(0, 0, 0);
    Time result = midnight - time;
    return result;
}
 
std::string Time::to_String() const
{
    return std::to_string(hour) + "::" + std::to_string(minute) + "::" + std::to_string(second);
}
 
Time::Time_of_day Time::time_of_day() const
{
    if (hour > 6 && hour < 12)
    {
        return Time::Time_of_day::Morning;
    }
    else if (hour == 12)
    {
        return Time::Time_of_day::Noon;
    }
    else if (hour > 12 && hour < 19)
    {
        return Time::Time_of_day::Evening;
    }
    else if (hour >= 19 || hour <= 6)
    {
        return Time::Time_of_day::Night;
    }
}
 
std::string Time::to_String(Time::Time_of_day x) const
{
    switch (x)
    {
        case Time::Time_of_day::Morning:
            return "Morning";
            break;
 
        case Time::Time_of_day::Noon:
            return "Noon";
            break;
 
        case Time::Time_of_day::Afternoon:
            return "Afternoon";
            break;
 
        case Time::Time_of_day::Evening:
            return  "Evening";
            break;
 
        case Time::Time_of_day::Night:
            return "Night";
            break;
    }
}
 
void Time::next_second()
{
    second++;
    if (second > 59)
    {
        second = 0;
        next_minute();
    }
}
 
void Time::next_minute()
{
    minute++;
    if (minute > 59)
    {
        minute = 0;
        next_hour();
    }
}
 
void Time::next_hour()
{
    hour++;
    if (hour > 23)
    {
        hour = 0;
    }
}
 
int main()
{
    Time time(14, 31, 24);
    
    std::cout << time.count_minutes() << "\n";
    std::cout << time.count_seconds() << "\n";
    std::cout << time.time_to_midnight().to_String() << "\n";
 
 
    return 0;
}