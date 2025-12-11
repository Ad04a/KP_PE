#pragma once

#include <string.h>

namespace DataUtils
{
    class IStringifiable
    {
        virtual std::string ToString() const = 0;
    };
}