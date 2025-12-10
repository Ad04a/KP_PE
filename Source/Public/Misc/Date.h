#pragma once

#include "Property.h"

#include "Interfaces/Misc/Displayable.h"
#include "Interfaces/Misc/Inputable.h"

#include "Exceptions/InvalidDateException.h"

class Date : PROPERTY_CLASS(Date), public IDisplayable, public IInputable
{   
private:
    bool bIsLeapYear = false;
    int MaxDay = 0;
public:
    PROPERTY(int, Year, GET, 
        SET
        {
            //if(VALUE<0) throw InvalidDateException("Year must be atleast 0");

            //insert some leap year logic
            FIELD = VALUE;
        }
    );
    PROPERTY(int, Month, GET, 
        SET
        {
            SELF->MaxDay = 0;
            switch(VALUE)
            {
                //case 0: throw InvalidDateException("Cannot set day before Month is initialised");
                case 2: SELF->MaxDay = (SELF->bIsLeapYear ? 29 : 28); break;
                case 4: case 6: case 9: case 11: SELF->MaxDay = 30; break;
                default : SELF->MaxDay = 31;
            }
            //if(VALUE<1 || VALUE>12) throw InvalidDateException("Month must be between 1 and 12");
            FIELD = VALUE;
        }
    );
    PROPERTY(int, Day, GET, 
        SET
        {
            /*if(VALUE<1 || VALUE>SELF->MaxDay) 
            {
                std::string message = "Day of month(" + std::to_string(2)+ ") must be between 1 and " + std::to_string(MaxDay);
                throw InvalidDateException(message);
            }*/

            FIELD = VALUE;
        }
    );

    std::string Display() const override;
    void Input() override;

    Date();
    Date(int InYear, int InMonth, int Day);

    bool IsValid() const;
};