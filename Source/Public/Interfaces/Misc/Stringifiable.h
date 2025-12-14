#pragma once

#include <string>

namespace DataUtils
{
    class IStringifiable
    {
        virtual std::string ToString() const = 0;
    };
}