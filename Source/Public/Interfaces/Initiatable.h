#pragma once

#include "iostream"

namespace UI
{
    class IInitiatable
    {
    protected:
        virtual void Initiate(std::istream* InStreamPtr, std::ostream* OutStreamPtr) = 0;

    };    
}


