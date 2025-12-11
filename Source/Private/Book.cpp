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

std::string Book::Display() const
{
    std::string Display = "Book: " + Title() + " [" + ISBN() 
    + " - " + PrintDate().Display() + "/" + ReleaseDate().Display() +"("+ 
    (IsApproved() ? ("Y - " + ApproveDate().Display()) : "N") +")]";
    return Display;
}

void Book::Input()
{

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