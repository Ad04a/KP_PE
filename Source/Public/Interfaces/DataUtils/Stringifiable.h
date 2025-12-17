#pragma once

#include <string>

namespace Data
{
    namespace Utils
    {
        class IStringifiable
        {
            virtual std::string ToString() const = 0;
        };
    }
}