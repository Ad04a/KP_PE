#include "PublisherUtils/BookRegistry.h"

#include "Exceptions/InvalidBookRegistryException.h"

PublisherUtils::BookRegistry::BookRegistry(std::set<BookEntry> InRegistry)
{
    Registry = InRegistry;
}

std::string PublisherUtils::BookRegistry::ToString() const
{
    if(Registry().size() <= 0) return "Book Catalog is empty!\n";
    std::string TempStr = "Catalog: \n";
    for(PublisherUtils::BookEntry Book : Registry())
    {
        TempStr += "    * " + Book.ToString()+"\n";
    }
    return TempStr;
}

std::ostream& PublisherUtils::BookRegistry::Output(std::ostream& OutStream) const
{
    OutStream<<"R "<<Registry().size()<<" ";
    for(PublisherUtils::BookEntry Book : Registry())
    {
        OutStream<<Book;
    }
    return OutStream;
}

std::istream& PublisherUtils::BookRegistry::Input(std::istream& InStream)
{
    char ID;
    InStream>>ID;
    if(ID != 'R') throw InvalidBookRegistryException("Invalid data format");
    
    int NumBooks;
    InStream>>NumBooks;
    std::set<BookEntry> TempRegistry;
    for(int i=0 ; i<NumBooks; i++)
    {
        BookEntry TempBook;
        InStream>>TempBook;
        TempRegistry.insert(TempBook);
    }
    Registry = TempRegistry;
    return InStream;
}

void PublisherUtils::BookRegistry::Enter(std::istream& InStream, std::ostream& OutStream)
{
    int NumBooks;
    OutStream<<"Number of books to be entered: ";
    InStream>>NumBooks;
    while(NumBooks < 0)
    {
        OutStream<<"Number of books must be >= 0 : ";
        InStream>>NumBooks;
    }
    
    std::set<BookEntry> TempRegistry;
    for(int i=0 ; i<NumBooks; i++)
    {
        BookEntry TempBook;
        OutStream<<"Enter book number "<<i+1<<":\n";
        TempBook.Enter(InStream, OutStream);
        TempRegistry.insert(TempBook);    
    }
    Registry = TempRegistry;
   
}
