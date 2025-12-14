#pragma once

#include "Interfaces/Dispatchable.h"

namespace System
{
    
    class BookStoreHandler : public IDispatchable
    {
    
    public:
        //BookStoreHandler(){};
  
    public:    
        virtual void Dispatch(std::istream& InStream, std::ostream& OutStream) const override;
    };
    
}