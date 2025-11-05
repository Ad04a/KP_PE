#include "../Public/Book.h"

//Book::NumPublished = 0;

Book::Book(string InTitle, string InISBN, vector<string> InAuthors, Date InPrintDate, Date InReleaseDate)
{
    SetTitle(InTitle);
    SetISBN(InISBN);
    SetAuthors(InAuthors);
    SetPrintDate(InPrintDate);
    SetReleaseDate(InReleaseDate);
    ApproveDate = Date();
}

string Book::GetTitle()
{
    return Title;
}
void Book::SetTitle(string InTitle)
{

}

string Book::GetISBN()
{
    return ISBN;
}
void Book::SetISBN(string InISBN)
{

}

vector<string> Book::GetAuthors()
{
    return Authors;
}
void Book::SetAuthors(vector<string> InAuthors)
{

}

int Book::GetPublishedID()
{
    return PublishId;
}

Date Book::GetPrintDate()
{
    return PrintDate;
}
void Book::SetPrintDate(Date InPrintDate)
{

}

Date Book::GetReleaseDate()
{
    return ReleaseDate;
}
void Book::SetReleaseDate(Date InReleaseDate)
{

}

Date Book::GetApproveDate()
{
    return ApproveDate;
}
void Book::SetApproveDate(Date InApproveDate)
{

}

bool Book::IsApproved()
{
    return ApproveDate.IsValid();
}