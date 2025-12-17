#pragma once

#include "iostream"

namespace Data
{
    namespace Utils
    {
        class IEnterable
        {
            virtual void Enter(std::istream& InStream, std::ostream& OutStream) = 0;

        };
    }
}