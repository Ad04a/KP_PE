#include "Misc/Date.h"

Date::Date()
{
    Year = 0;
    Month = 0;
    Day = 0;
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
    return Year() && Month() && Day(); //some date validation
}