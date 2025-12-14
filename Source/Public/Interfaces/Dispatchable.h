#pragma once

#include <iostream>

namespace System
{
    class IDispatchable
    {
    public:
        virtual void Dispatch(std::istream& InStream, std::ostream& OutStream) const = 0;

    };
}
