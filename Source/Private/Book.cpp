#include "Book.h"

#include "Exceptions/InvalidISBNException.h"

#include <iostream>

//int Book::NumPublished = 0;

// int main()
// {
//     cout<<"molq";
//     return 0;
// }

/*Book::Book()
{
    Title = "";
    ISBN = "";
    //Title = CPPUtils::Property<std::std::string>();
    //ISBN = CPPUtils::Property<std::std::string>();
}*/

bool Book::Approve(Book& InBook)
{
    if(InBook.IsApproved()) return false;
    InBook.ApproveDate = Date::Now();
    return true;
}

Book::Book(std::string InTitle, std::string InISBN, std::vector<std::string> InAuthors, Date InPrintDate, Date InReleaseDate)
{
    Title = InTitle;
    ISBN = InISBN;
    Authors = InAuthors;
    PrintDate = InPrintDate;
    ReleaseDate = InReleaseDate;
    ApproveDate = Date();
    //PublishId = Book::NumPublished++;
}

int Book::GetPublishedID() const
{
    return PublishId;
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
    if(ID != 'B'){ std::cout<<"ID: "<<ID<<")";  return InStream;}
    
    int NumAuthors, ReadLenght;

    InStream >> ReadLenght>>std::ws;
    char TitleName[100];
    InStream.read(TitleName, ReadLenght);
    TitleName[ReadLenght] = '\0';
    Title = std::string(TitleName);
    
    InStream>>ISBN()>>PrintDate()>>ReleaseDate();

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

/*
ostream& operator<<(ostream& os, const Book& InBook)
{
    //os<<InBook.Title()<<" ("<<InBook.ISBN()<<")[" << InBook.PublishId << "] From: ";
    for(unsigned int i=0; i<InBook.Authors.size(); i++) os<<InBook.Authors[i]<<", ";
    os<<"\b\b Published: "<<InBook.PrintDate<<"-"<<InBook.ReleaseDate<<" Approved: ";
    if(InBook.IsApproved()) os<<"Yes ["<<InBook.ApproveDate<<"]";
    else os<<"No";
    return os;
}

istream& operator>>(istream& is, Book& OutBook)
{
    return is;
}*/

/*int main()
{
    std::cout<<"Book main\n";
    //Book b;
    //b.ISBN_II = 19;
    //std::cout<<b.ISBN_II();
    return 0;
}*/