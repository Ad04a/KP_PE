#include "PublisherUtils/BookEntry.h"

#include <format>


Data::PublisherUtils::BookEntry::BookEntry(Book InHeldBook, float InPrice)
{
    HeldBook = InHeldBook;
    Price = InPrice;
}

std::string Data::PublisherUtils::BookEntry::ToString() const
{
    return HeldBook().ToString() + " - Price: " + std::format("{:.2f}", Price());
}

std::ostream& Data::PublisherUtils::BookEntry::Output(std::ostream& OutStream) const
{
    OutStream << "E "<<HeldBook()<<Price<<" ";
    return OutStream;
}

std::istream& Data::PublisherUtils::BookEntry::Input(std::istream& InStream)
{
    char ID;
    InStream>>ID;
    if(ID != 'E') throw Exceptions::InvalidBookEntryException("Invalid data format");
    
    
    float InPrice;

    InStream>>HeldBook()>> InPrice;
    Price = InPrice;

    return InStream;
}

void Data::PublisherUtils::BookEntry::Enter(std::istream& InStream, std::ostream& OutStream)
{
    HeldBook().Enter(InStream, OutStream);

    while(true)
    {
        try
        {
            OutStream<<"Enter the new book's price:";
            float InPrice;
            InStream >> InPrice;
            Price = InPrice;
        }
        catch(const std::runtime_error& Error)
        {   
            OutStream<<Error.what()<<"\n"; continue;
        } 
        break;   
    }
}

bool Data::PublisherUtils::BookEntry::operator<(const BookEntry& Other) const {
    // order by name, then age
    if (Price() != Other.Price())
        return Price() < Other.Price();
    return HeldBook() < Other.HeldBook();
}