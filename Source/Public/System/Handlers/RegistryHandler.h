#pragma once

#include "Interfaces/Dispatchable.h"

namespace System
{
    
    class RegistryHandler : public IDispatchable
    {
    
    public:
        //RegistryHandler(){};
  
    public:    
        virtual void Dispatch(std::istream& InStream, std::ostream& OutStream) const override;
    };
    
}