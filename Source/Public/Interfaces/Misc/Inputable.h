#pragma once

#include "istream"

namespace DataUtils
{
    class IInputable
    {
        virtual std::istream& Input(std::istream& InStream) = 0;

        friend std::istream& operator>>(std::istream& InStream, IInputable& Inputable)
        {
            return Inputable.Input(InStream);
        }

    };
}
