#include "Misc/Date.h"

#include "Exceptions/InvalidDateException.h"

bool Data::Date::IsLeapYear(int InYear)
{
    if (InYear % 400 == 0) return true;
    if (InYear % 100 == 0) return false;
    if (InYear % 4 == 0) return true;
    return false;
}

int Data::Date::GetDaysForMonth(int InMonth, bool bInIsLeapYear)
{
    switch(InMonth)
    {
        case 2: return (bInIsLeapYear ? 29 : 28); 
        case 4: case 6: case 9: case 11: return 30; 
        default : return 31;
    }
}

bool Data::Date::IsValidYear(int InYear)
{
    return InYear >= 0;
}

bool Data::Date::IsValidMonth(int InMonth)
{
    return InMonth >= 1 && InMonth <= 12;
}

bool Data::Date::IsValidDayForMonth(int InDay, int InMonth, bool bInIsLeapYear)
{
    int MaxDays = GetDaysForMonth(InMonth, bInIsLeapYear);
    return InDay >= 1 && InDay <= MaxDays;
}

Data::Date Data::Date::Now()
{
    return Data::Date(2025,12,11);
}

Data::Date::Date(int InYear, int InMonth, int InDay)
{
    Year = InYear;
    Month = InMonth;
    Day = InDay;
}

bool Data::Date::IsValid() const
{
    return IsValidYear(Year) && IsValidMonth(Month) && IsValidDayForMonth(Day, Month, IsLeapYear(Year)); 
}

std::string Data::Date::ToString() const
{
    std::string Out = std::to_string(Year) + '.' + std::to_string(Month) + '.' + std::to_string(Day);
    return Out;
}

std::ostream& Data::Date::Output(std::ostream& OutStream) const
{
    OutStream << "D " << Year() <<" "<< Month()<<" " << Day()<<" ";
    return OutStream;
}

std::istream& Data::Date::Input(std::istream& InStream)
{
    char ID;
    InStream>>ID;
    if(ID != 'D') throw Exceptions::InvalidDateException("Invalid data format");

    int InYear, InMonth, InDay;

    InStream >> InYear >> InMonth >> InDay;

    Year = InYear;
    Month= InMonth;
    Day = InDay;

    if(IsValid() == false) throw Exceptions::InvalidDateException("Invalid data value");

    return InStream;
}

void Data::Date::Enter(std::istream& InStream, std::ostream& OutStream)
{
    
    int InYear, InMonth, InDay;
    
    OutStream<<"Year: ";
    InStream>>InYear;
    while(IsValidYear(InYear) == false)
    {
        OutStream<<"Year must be greater than 0!\nYear: ";
        InStream>>InYear;
    }

    OutStream<<"Month: ";
    InStream>>InMonth;
    while(IsValidMonth(InMonth) == false)
    {
        OutStream<<"Month must be between 1 and 12!\nMonth: ";
        InStream>>InMonth;
    }

    OutStream<<"Day: ";
    InStream>>InDay;
    while(IsValidDayForMonth(InDay, InMonth, IsLeapYear(InYear)) == false)
    {
        OutStream<<"Day must be between 1 and "<<GetDaysForMonth(InMonth, IsLeapYear(InYear))<<"!\nDay: ";
        InStream>>InDay;
    }
    
    Year = InYear;
    Month = InMonth;
    Day = InDay;
}

bool Data::Date::operator>( const Data::Date& b) const
{
    return (Year() >= b.Year()) && (Month() >= b.Month()) && (Day() > b.Day());
}

bool Data::Date::operator<(const Data::Date& b) const
{
    return (Year() <= b.Year()) && (Month() <= b.Month()) && (Day() < b.Day());
}

bool Data::Date::operator==(const Data::Date& b) const
{
    return (Year() == b.Year()) && (Month() == b.Month()) && (Day() == b.Day());
}

bool Data::Date::operator!=(const Data::Date& b) const
{
    return !(*this == b);
}