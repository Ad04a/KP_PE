#include "Book.h"

#include <limits>

Book::Book(std::string InTitle, std::string InISBN, std::vector<std::string> InAuthors, Date InPrintDate, Date InReleaseDate)
{
    Title = InTitle;
    ISBN = InISBN;
    Authors = InAuthors;
    PrintDate = InPrintDate;
    ReleaseDate = InReleaseDate;
    ApproveDate = Date();
}

bool Book::IsApproved() const
{
    return ApproveDate().IsValid();
}

std::string Book::ToString() const
{
    std::string Out = "Book: " + Title() + " [" + ISBN() 
    + " - " + PrintDate().ToString() + "/" + ReleaseDate().ToString() +"("+ 
    (IsApproved() ? ("Y - " + ApproveDate().ToString()) : "N") +")]";
    return Out;
}

std::ostream& Book::Output(std::ostream& OutStream) const
{
    OutStream << "B " << Title().size()<<" "<< Title() << " " << ISBN() << " " << PrintDate() << " " << ReleaseDate() << " " 
    << (IsApproved() ? "Y "  : "N ");
    if( IsApproved() ) OutStream << ApproveDate() << " ";
    OutStream<<Authors().size()<<" ";
    for(size_t i=0 ; i<Authors().size(); i++)
    {
        OutStream<<Authors()[i].size()<<" "<<Authors()[i]<<" ";
    }
    return OutStream;
}

std::istream& Book::Input(std::istream& InStream)
{
    char ID;
    InStream>>ID;
    if(ID != 'B') throw InvalidBookException("Invalid data format");
    
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

void Book::Enter(std::istream& InStream, std::ostream& OutStream)
{
    OutStream<<"Enter book's name: ";
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
            Date d = Date();
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
    InStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(Approve == 'y')
    {
        while(true)
        {
            try
            {
                OutStream<<"Enter book's Approve date: \n";
                Date d = Date();
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
    InStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::vector<std::string> InAuthors;
    for(int i=0; i<NumAuthors; i++)
    {
        OutStream<<"Enter authors number "<<i+1<<": ";
        std::getline(InStream, TempString);
        InAuthors.push_back(TempString);
    }
    Authors = InAuthors;
}

bool Book::operator<(const Book& Other) const
{
    if (Title() != Other.Title())
        return Title() < Other.Title();
    return ISBN() < Other.ISBN();
}