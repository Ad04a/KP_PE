#include "Misc/Date.h"

bool Date::IsLeapYear(int InYear)
{
    if (InYear % 400 == 0) return true;
    if (InYear % 100 == 0) return false;
    if (InYear % 4 == 0) return true;
    return false;
}

Date::Date(int InYear, int InMonth, int InDay)
{
    Year = InYear;
    Month = InMonth;
    Day = InDay;
}

std::string Date::Display() const
{
    std::string Display = std::to_string(Year) + '/' + std::to_string(Month) + '/' + std::to_string(Day);
    return Display;
}

void Date::Input()
{

}

bool Date::IsValid() const
{
    if(Year < 0) return false;
    if(Month < 1 || Month > 12) return false;
    if(Day < 1 || Day > _MaxDay) return false;
    return true; 
}