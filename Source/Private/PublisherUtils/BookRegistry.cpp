#include "PublisherUtils/BookRegistry.h"

PublisherUtils::BookRegistry::BookRegistry()
{
}

std::string PublisherUtils::BookRegistry::ToString() const
{
    std::string TempStr = "Books: \n";
    for(PublisherUtils::BookEntry Book : Registry())
    {
        TempStr += "* " + Book.ToString();
    }
    return TempStr;
}

std::ostream& PublisherUtils::BookRegistry::Output(std::ostream& OutStream) const
{
    return OutStream;
}

std::istream& PublisherUtils::BookRegistry::Input(std::istream& InStream)
{
    return InStream;
}

void PublisherUtils::BookRegistry::Enter(std::istream& InStream, std::ostream& OutStream)
{

}
