#pragma once

#include "Property.h"

#include "Interfaces/Misc/Outputable.h"
#include "Interfaces/Misc/Stringifiable.h"
#include "Interfaces/Misc/Inputable.h"
#include "Interfaces/Misc/Enterable.h"

class Date : PROPERTY_CLASS(Date), public DataUtils::IOutputable, public DataUtils::IStringifiable, public DataUtils::IInputable, public DataUtils::IEnterable
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
    
    virtual bool IsValid() const;

    virtual std::string ToString() const override;
    virtual std::ostream& Output(std::ostream& OutStream) const override;
    virtual std::istream& Input(std::istream& InStream) override;
    virtual void Enter(std::istream& InStream, std::ostream& OutStream) override;

    
    bool operator>(const Date& b) const;
    bool operator<(const Date& b) const;
    bool operator==(const Date& b) const;
    bool operator!=(const Date& b) const;
};