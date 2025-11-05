#include "Misc/Date.h"
#include "Exceptions/InvalidDateException.h"

#include <iostream>

Date::Date()
{
    Year = -1;
    Month = -1;
    Day = -1;
}

Date::Date(int InYear, int InMonth, int InDay)
{
    SetYear(InYear);
    SetMonth(InMonth);
    SetDay(InDay);
}

int Date::GetYear() const
{
    return Year;
}
void Date::SetYear(int InYear)
{
    if(InYear<0) throw InvalidDateException("Year must be atleast 0");
    Year = InYear;
}

int Date::GetMonth() const
{
    return Month;
}
void Date::SetMonth(int InMonth)
{
    if(InMonth<1 || InMonth>12) throw InvalidDateException("Month must be between 1 and 12");
    Month = InMonth;
}

int Date::GetDay() const
{
    return Day;
}
void Date::SetDay(int InDay)
{
    int MaxDay = 0;
    switch(Month)
    {
        case -1: throw InvalidDateException("Cannot set day before Month is initialised");
        case 2: MaxDay = 28; break;
        case 4: case 6: case 9: case 11: MaxDay = 30; break;
        default : MaxDay = 31;
    }

    if(InDay<1 || InDay>MaxDay) 
    {
        string message = "Day of month(" + to_string(Month)+ ") must be between 1 and " + to_string(MaxDay);
        throw InvalidDateException(message);
    }

    Day = InDay;
}

bool Date::IsValid() const
{
    return !(Year == -1 || Month == -1 || Day == -1);
}

ostream& operator<<(ostream& os, const Date& InDate)
{
    os << InDate.Year << '/' << InDate.Month << '/' << InDate.Day;
    return os;
}

istream& operator>>(istream& is, Date& OutDate)
{
    char Slash1, Slash2;
    int Year, Month, Day;

    is >> Year >> Slash1 >> Month >> Slash2 >> Day;

    /*if (is >> Year >> Slash1 >> Month >> Slash2 >> Day) {
        if (Slash1 != '/' || Slash2 != '/') {
            is.setstate(std::ios::failbit);
        }
    }*/

    OutDate.SetYear(Year);
    OutDate.SetMonth(Month);
    OutDate.SetDay(Day);

    return is;
}