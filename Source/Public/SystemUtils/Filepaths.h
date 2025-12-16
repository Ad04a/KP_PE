#pragma once

#include <string>
#include <fstream>

namespace SystemUtils
{
    inline std::string IntermediateFolder(){ return "./Intermediate/";}
    inline std::string PublisherFolder(){return IntermediateFolder() + "Publishers/";}
    inline std::string PublisherEntryFile(){ return PublisherFolder() + "Publishers.txt";}
}