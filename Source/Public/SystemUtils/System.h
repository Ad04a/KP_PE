#pragma once

#include <string>
#include <map>
#include "Property.h"

#include "SystemUtils/SystemHandlers.h"

namespace SystemUtils
{
    class System : public Handler
    {
    private:
        static std::string IntermediateFolder(){ return "./Intermediate/";}
        static std::string PublisherFolder(){return IntermediateFolder() + "Publishers/";}
        static std::string PublisherEntryFile(){ return PublisherFolder() + "Publishers.txt";}

        RegistryHandler RegistryManager;
        PublisherHandler PublisherManager;
        BookStoreHandler StoreManager;

    public:              
        System();

    };
}

