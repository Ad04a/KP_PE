#pragma once

#include "iostream"

namespace DataUtils
{
    class IEnterable
    {
        virtual void Enter(std::istream& InStream, std::ostream& OutStream) = 0;

    };
}