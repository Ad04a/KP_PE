#include "System/Dispatcher.h"

#include <fstream>
#include <filesystem>
#include <windows.h>

#include "Exceptions/FileException.h"

System::Dispatcher::Dispatcher()
{
    if (!std::filesystem::exists(IntermediateFolder())) std::filesystem::create_directory(IntermediateFolder());
    if (!std::filesystem::exists(PublisherFolder())) std::filesystem::create_directory(PublisherFolder());
    if (!std::filesystem::exists(PublisherEntryFile()))
    {
        std::ofstream PublisherEntry(PublisherEntryFile());
        if (!PublisherEntry) {
            throw FileException("Can not create file: " + PublisherEntryFile());
        }
        PublisherEntry<<"temp text";
        PublisherEntry.close();
    }
}

bool System::Dispatcher::AddOption(std::string Option, const System::IDispatchable& Entry)
{
    auto[Iterator, Result] = DispatchMap().insert({Option, Entry});
    return Result;
}


bool System::Dispatcher::Dispatch(std::string Option, std::istream& InStream, std::ostream& OutStream)
{
    auto it = DispatchMap().find(Option);
    if (it == DispatchMap().end()) return false;

    it->second.Dispatch(InStream, OutStream);
    return true;
}