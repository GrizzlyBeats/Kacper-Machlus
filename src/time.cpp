#include <iostream>
#include "Time.h"
 
 
Time::Time()
{
    hour = 0;
    minute = 0;
    second = 0;
}
 
 
std::string Time::to_String() const
{
    return std::to_string(hour) + "::" + std::to_string(minute) + "::" + std::to_string(second);
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
    Time time;
    
    time.hour = 23;
    time.minute = 59;
    time.second = 59;
    std::cout << time.to_String() <<"\n"; 
    time.next_second();
    std::cout << time.to_String() << "\n\n";
 
    time.hour = 23;
    time.minute = 59;
    time.second = 59;
    std::cout << time.to_String() << "\n";
    time.next_minute();
    std::cout << time.to_String() << "\n\n";
 
    time.hour = 23;
    time.minute = 59;
    time.second = 59;
    std::cout << time.to_String() << "\n";
    time.next_hour();
    std::cout << time.to_String() << "\n\n";
 
    return 0;
}