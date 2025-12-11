#pragma once

#include "Property.h"

#include "Interfaces/Misc/Displayable.h"
#include "Interfaces/Misc/Inputable.h"

class Date : PROPERTY_CLASS(Date), public IDisplayable, public IInputable
{   
public:
    static bool IsLeapYear(int InYear);
    static int GetDaysForMonth(int InMonth, bool bInIsLeapYear);
    static bool IsValidYear(int InYear);
    static bool IsValidMonth(int InMonth);
    static bool IsValidDayForMonth(int InDay, int InMonth, bool bInIsLeapYear);
    static Date Now();

    PROPERTY(int, Year, GET, PRIVATE_SET);
    PROPERTY(int, Month, GET, PRIVATE_SET);
    PROPERTY(int, Day, GET, PRIVATE_SET);

    Date(int InYear, int InMonth, int Day);
    Date() : Date(0, 0, 0){}
    
    bool IsValid() const;

    std::string Display() const override;
    void Input() override;
};