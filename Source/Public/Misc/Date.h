#pragma once

#include "Property.h"

#include "Interfaces/Misc/Displayable.h"
#include "Interfaces/Misc/Inputable.h"

class Date : PROPERTY_CLASS(Date), public IDisplayable, public IInputable
{   
    static bool IsLeapYear(int InYear);
private:
    bool _bIsLeapYear = false;
    int _MaxDay = 0;
public:
    PROPERTY(int, Year, GET, 
        SET
        {
            SELF->_bIsLeapYear = IsLeapYear(VALUE);
            FIELD = VALUE;
        }
    );
    PROPERTY(int, Month, GET, 
        SET
        {
            SELF->_MaxDay = 0;
            switch(VALUE)
            {
                case 2: SELF->_MaxDay = (SELF->_bIsLeapYear ? 29 : 28); break;
                case 4: case 6: case 9: case 11: SELF->_MaxDay = 30; break;
                default : SELF->_MaxDay = 31;
            }
            FIELD = VALUE;
        }
    );
    PROPERTY(int, Day, GET, SET);

    std::string Display() const override;
    void Input() override;

    Date(int InYear, int InMonth, int Day);
    Date() : Date(0, 0, 0){}
    
    bool IsValid() const;
};