#include "Book.h"

#include <limits>

Data::Book::Book(std::string InTitle, std::string InISBN, std::vector<std::string> InAuthors, Data::Date InPrintDate, Data::Date InReleaseDate)
{
    Title = InTitle;
    ISBN = InISBN;
    Authors = InAuthors;
    PrintDate = InPrintDate;
    ReleaseDate = InReleaseDate;
    ApproveDate = Data::Date();
}

bool Data::Book::IsApproved() const
{
    return ApproveDate().IsValid();
}

std::string Data::Book::ToString() const
{
    std::string Out = Title() + " [ISBN:" + ISBN() 
    + " - Print: " + PrintDate().ToString() + " / Release: " + ReleaseDate().ToString() +" ("+ 
    (IsApproved() ? ("Approved: " + ApproveDate().ToString()) : "Not approved yet") +")]";
    return Out;
}

std::ostream& Data::Book::Output(std::ostream& OutStream) const
{
    OutStream << "B " << Title().size()<<" "<< Title() << " " << ISBN() << " " << PrintDate() << ReleaseDate() << (IsApproved() ? "Y "  : "N ");
    if( IsApproved() ) OutStream << ApproveDate();
    OutStream<<Authors().size()<<" ";
    for(size_t i=0 ; i<Authors().size(); i++)
    {
        OutStream<<Authors()[i].size()<<" "<<Authors()[i]<<" ";
    }
    return OutStream;
}

std::istream& Data::Book::Input(std::istream& InStream)
{
    char ID;
    InStream>>ID;
    if(ID != 'B') throw Exceptions::InvalidBookException("Invalid data format");
    
    int NumAuthors, ReadLenght;

    InStream >> ReadLenght>>std::ws;
    char TitleName[100];
    InStream.read(TitleName, ReadLenght);
    TitleName[ReadLenght] = '\0';
    Title = std::string(TitleName);
    std::string InISBN;
    InStream>>InISBN>>PrintDate()>>ReleaseDate();

    ISBN = InISBN;

    InStream>>ID;
    if(ID == 'Y') InStream>>ApproveDate();

    InStream>>NumAuthors;
    std::vector<std::string> InAuthors;
    for(int i = 0; i<NumAuthors; i++)
    {
        InStream >> ReadLenght>>std::ws;
        char AuthorName[100];
        InStream.read(AuthorName, ReadLenght);
        AuthorName[ReadLenght] = '\0';
        InAuthors.push_back(std::string(AuthorName));
    }
    Authors = InAuthors;

    return InStream;
}

void Data::Book::Enter(std::istream& InStream, std::ostream& OutStream)
{
    OutStream<<"Enter book's title: ";
    InStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(InStream, Title());

    std::string TempString;
    while(true)
    {
        try
        {
            OutStream<<"Enter book's ISBN: ";
            std::getline(InStream, TempString);
            ISBN = TempString;
        }
        catch(const std::runtime_error& Error)
        {   
            OutStream<<Error.what()<<"\n"; continue;
        } 
        break;   
    }
    OutStream<<"Enter book's print date: \n";
    PrintDate().Enter(InStream, OutStream);

    while(true)
    {
        try
        {
            OutStream<<"Enter book's release date: \n";
            Data::Date d = Data::Date();
            d.Enter(InStream, OutStream);
            ReleaseDate = d;
        }
        catch(const std::runtime_error& Error)
        {   
            OutStream<<Error.what()<<"\n"; continue;
        } 
        break;   
    }

    unsigned char Approve;
    OutStream<<"Is the book approved (Y/N): ";
    InStream >> Approve;
    if(Approve >= 'a') Approve-=('a' - 'A');
    while(Approve!='Y' && Approve!='N')
    {
        OutStream<<"Only Y and N: ";
        InStream >> Approve;
    }
    if(Approve == 'Y')
    {
        while(true)
        {
            try
            {
                OutStream<<"Enter book's Approve date: \n";
                Data::Date d = Data::Date();
                d.Enter(InStream, OutStream);
                ApproveDate = d;
            }
            catch(const std::runtime_error& Error)
            {   
                OutStream<<Error.what()<<"\n"; continue;
            } 
            break;   
        }
    }

    OutStream<<"Enter number of authors: ";
    int NumAuthors;
    InStream>>NumAuthors;
    while(NumAuthors <= 0)
    {
        OutStream<<"Number of authors must be atleat 1: ";
        InStream>>NumAuthors;
    }
    InStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::vector<std::string> InAuthors;
    for(int i=0; i<NumAuthors; i++)
    {
        OutStream<<"Enter the name of author number "<<i+1<<": ";
        std::getline(InStream, TempString);
        InAuthors.push_back(TempString);
    }
    Authors = InAuthors;
}

bool Data::Book::operator<(const Book& Other) const
{
    if (Title() != Other.Title())
        return Title() < Other.Title();
    return ISBN() < Other.ISBN();
}