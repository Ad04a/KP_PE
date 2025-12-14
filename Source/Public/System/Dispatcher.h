#pragma once

#include <string>
#include <map>
#include "Property.h"

#include "Interfaces/Dispatchable.h"

namespace System
{
    class Dispatcher : PROPERTY_CLASS(Dispatcher)
    {
    private:
        static std::string IntermediateFolder(){ return "./Intermediate/";}
        static std::string PublisherFolder(){return IntermediateFolder() + "Publishers/";}
        static std::string PublisherEntryFile(){ return PublisherFolder() + "Publishers.txt";}
        
        using DispatchMapType = std::map<std::string, const IDispatchable&>; 
        PROPERTY(DispatchMapType, DispatchMap, GET, SET);

    public:              
        Dispatcher();

        bool AddOption(std::string Option, const IDispatchable& Entry);
        bool RemoveOption(std::string Option){return false;}

        bool Dispatch(std::string Option, std::istream& InStream, std::ostream& OutStream);
    };
}

