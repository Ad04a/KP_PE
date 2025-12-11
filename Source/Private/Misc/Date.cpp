#include "Misc/Date.h"

bool Date::IsLeapYear(int InYear)
{
    if (InYear % 400 == 0) return true;
    if (InYear % 100 == 0) return false;
    if (InYear % 4 == 0) return true;
    return false;
}

int Date::GetDaysForMonth(int InMonth, bool bInIsLeapYear)
{
    switch(InMonth)
    {
        case 2: return (bInIsLeapYear ? 29 : 28); 
        case 4: case 6: case 9: case 11: return 30; 
        default : return 31;
    }
}

bool Date::IsValidYear(int InYear)
{
    return InYear >= 0;
}

bool Date::IsValidMonth(int InMonth)
{
    return InMonth >= 1 && InMonth <= 12;
}

bool Date::IsValidDayForMonth(int InDay, int InMonth, bool bInIsLeapYear)
{
    int MaxDays = GetDaysForMonth(InMonth, bInIsLeapYear);
    return InDay >= 1 && InDay <= MaxDays;
}

Date Date::Now()
{
    return Date(11,12,2025);
}

Date::Date(int InYear, int InMonth, int InDay)
{
    Year = InYear;
    Month = InMonth;
    Day = InDay;
}

bool Date::IsValid() const
{
    return IsValidYear(Year) && IsValidMonth(Month) && IsValidDayForMonth(Day, Month, IsLeapYear(Year)); 
}

std::string Date::Display() const
{
    std::string Display = std::to_string(Year) + '.' + std::to_string(Month) + '.' + std::to_string(Day);
    return Display;
}

void Date::Input()
{

}

