#include "PublisherUtils/BookRegistry.h"

#include "Exceptions/InvalidBookRegistryException.h"

PublisherUtils::BookRegistry::BookRegistry(std::set<BookEntry> InRegistry)
{
    Registry = InRegistry;
}

std::string PublisherUtils::BookRegistry::ToString() const
{
    if(Registry().size() <= 0) return "Book registry is empty!";
    std::string TempStr = "Collection of books: \n";
    for(PublisherUtils::BookEntry Book : Registry())
    {
        TempStr += "* " + Book.ToString();
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
    Book TempBook;
    std::set<BookEntry> TempRegistry;
    for(int i=0 ; i<NumBooks; i++)
    {
        InStream>>TempBook;
        TempRegistry.insert(TempBook);
    }
    Registry = TempRegistry;
    return InStream;
}

void PublisherUtils::BookRegistry::Enter(std::istream& InStream, std::ostream& OutStream)
{
    int NumBooks;
    OutStream<<"Enter number of books to be entered: ";
    InStream>>NumBooks;
    while(NumBooks < 0)
    {
        OutStream<<"Number of books must be >= 0 : ";
        InStream>>NumBooks;
    }

    Book TempBook;
    std::set<BookEntry> TempRegistry;
    for(int i=0 ; i<NumBooks; i++)
    {
        while(true)
        {
            try
            {
                InStream>>TempBook;
            }
            catch(const std::runtime_error& Error)
            {   
                OutStream<<Error.what()<<"\n"; continue;
            } 
            
            TempRegistry.insert(TempBook);
            break;   
        }
    }

   
}
