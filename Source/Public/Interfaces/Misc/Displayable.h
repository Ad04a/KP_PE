#pragma once

#include <string>
#include <ostream>

class IDisplayable
{
    virtual std::string Display() const = 0;

    friend std::ostream& operator << (std::ostream& os, const IDisplayable &Displayable)
    {
        os<<Displayable.Display();

        return os;
    }
};