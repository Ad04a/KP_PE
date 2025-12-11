#pragma once

#include <string>
#include <ostream>

namespace
{
    class IDisplayable
    {
        virtual std::string Display() = 0;
    }

    inline std::ostream& operator<<(std::ostream& out, const IDisplayable& value)
    {
        out<<value.Display();
    }
}

