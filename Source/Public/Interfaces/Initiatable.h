#pragma once

#include "iostream"

class IInitiatable
{
protected:
    virtual void Initiate(std::istream* InStreamPtr, std::ostream* OutStreamPtr) = 0;

};
