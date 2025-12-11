#pragma once

#include "Interfaces/Misc/Outputable.h"
#include "Interfaces/Misc/Stringifiable.h"

namespace DataUtils
{
    class IDisplayable : public IOutputable, public IStringifiable
    {
        virtual std::string ToString() const override = 0;

        inline std::ostream& Output(std::ostream& OutStream) const override
        {
            OutStream << ToString();
            return OutStream;
        }
    };
}
