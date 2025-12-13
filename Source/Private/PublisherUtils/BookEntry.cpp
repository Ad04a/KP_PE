#include "PublisherUtils/BookEntry.h"

PublisherUtils::BookEntry::BookEntry(Book InHeldBook, float InPrice)
{
    HeldBook = InHeldBook;
    Price = InPrice;
}

std::string PublisherUtils::BookEntry::ToString() const
{
    return HeldBook().ToString() + " - Price: " + std::to_string(Price());
}

std::ostream& PublisherUtils::BookEntry::Output(std::ostream& OutStream) const
{
    return OutStream;
}

std::istream& PublisherUtils::BookEntry::Input(std::istream& InStream)
{
    return InStream;
}

void PublisherUtils::BookEntry::Enter(std::istream& InStream, std::ostream& OutStream)
{

}

bool PublisherUtils::BookEntry::operator<(const BookEntry& Other) const {
    // order by name, then age
    if (Price() != Other.Price())
        return Price() < Other.Price();
    return HeldBook() < Other.HeldBook();
}