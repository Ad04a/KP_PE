#pragma once

#include <ostream>

namespace DataUtils
{
    class IOutputable
    {
        virtual std::ostream& Output(std::ostream& OutStream) const = 0;

        friend std::ostream& operator<<(std::ostream& OutStream, const IOutputable& Outputable)
        {
            return Outputable.Output(OutStream);
        }
    };

    
}
