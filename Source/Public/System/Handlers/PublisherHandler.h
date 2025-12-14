#pragma once

#include <string>
#include "Property.h"

#include "Interfaces/Dispatchable.h"

namespace System
{
    
    class PublisherHandler : PROPERTY_CLASS(PublisherHandler), public IDispatchable
    {
    
    public:
        PROPERTY(std::string, PublisherName, GET, SET);

        //PublisherHandler(){};
  
        virtual void Dispatch(std::istream& InStream, std::ostream& OutStream) const override;
    };
    
}