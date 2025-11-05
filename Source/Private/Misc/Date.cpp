#include "../../Public/Misc/Date.h"
#include "../../Public/Exceptions/InvalidDateException.h"

Date::Date()
{
    Year = -1;
    Month = -1;
    Day = -1;
}

Date::Date(int InYear, int InMonth, int InDay)
{
    if(InYear<0) throw InvalidDateException(": Year must be atleast 0");
    if(InMonth<1 || InMonth>12) throw InvalidDateException(": Month must be between 1 and 12");
    int MaxDay = 0;
    switch(InMonth)
    {
        case 2: MaxDay = 28; break;
        case 4: case 6: case 9: case 11: MaxDay = 30; break;
        default : MaxDay = 31;
    }

    if(InDay<1 || InDay>MaxDay) 
    {
        string message = ": Day of month(" + to_string(InMonth)+ ") must be between 1 and " + to_string(MaxDay);
        throw InvalidDateException(message);
    }

    Year = InYear;
    Month = InMonth;
    Day = InDay;
}

bool Date::IsValid()
{
    return !(Year == -1 || Month == -1 || Day == -1);
}