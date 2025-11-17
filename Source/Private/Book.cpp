#include "Book.h"

#include "Exceptions/InvalidISBNException.h"

#include <iostream>

//int Book::NumPublished = 0;

// int main()
// {
//     cout<<"molq";
//     return 0;
// }

Book::Book()
{
    Title = "";
    ISBN = "";
    //Title = CPPUtils::Property<std::std::string>();
    //ISBN = CPPUtils::Property<std::std::string>();
}

Book::Book(std::string InTitle, std::string InISBN, std::vector<std::string> InAuthors, Date InPrintDate, Date InReleaseDate) : Book()
{
    
    //SetISBN(InISBN);
    //SetAuthors(InAuthors);
    SetPrintDate(InPrintDate);
    SetReleaseDate(InReleaseDate);
    ApproveDate = Date();
    //PublishId = Book::NumPublished++;
}

void Book::SetISBN(std::string InISBN)
{

    if(InISBN.size() != 10 && InISBN.size() != 13) throw InvalidISBNException("ISBN must be between 10 and 13 digits");
    
    for(unsigned int i=0; i<InISBN.size(); i++)
    {
        if(InISBN[i]<'0' || InISBN[i]>'9') throw InvalidISBNException("ISBN must be between 10 and 13 DIGITS");
    }

    //ISBN = InISBN;

}

/*std::vector<std::string> Book::GetAuthors() const
{
    return Authors;
}*/
void Book::SetAuthors(std::vector<std::string> InAuthors)
{
    cout<<"bruh";
    //Authors = InAuthors;
}

int Book::GetPublishedID() const
{
    return PublishId;
}

Date Book::GetPrintDate() const
{
    return PrintDate;
}
void Book::SetPrintDate(Date InPrintDate)
{
    PrintDate = InPrintDate;
}
void Book::SetPrintDate(int InYear, int InMonth, int InDay)
{
    SetPrintDate(Date(InYear, InMonth, InDay));
}

Date Book::GetReleaseDate() const
{
    return ReleaseDate;
}
void Book::SetReleaseDate(Date InReleaseDate)
{
    ReleaseDate = InReleaseDate;
}
void Book::SetReleaseDate(int InYear, int InMonth, int InDay)
{
    SetReleaseDate(Date(InYear, InMonth, InDay));
}

Date Book::GetApproveDate() const
{
    return ApproveDate;
}
void Book::SetApproveDate(Date InApproveDate)
{
    ApproveDate = InApproveDate;
}
void Book::SetApproveDate(int InYear, int InMonth, int InDay)
{
    SetApproveDate(Date(InYear, InMonth, InDay));
}

bool Book::IsApproved() const
{
    return ApproveDate.IsValid();
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