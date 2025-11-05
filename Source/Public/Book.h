#pragma once

#include <string>
#include <vector>
#include "Misc/Date.h"

using namespace std;

class Book
{

    private:

    static int NumPublished;

    string Title;
    string ISBN;
    vector<string> Authors;
    int PublishId;
    Date PrintDate;
    Date ReleaseDate;
    Date ApproveDate;

    public:

    Book(string InTitle, string InISBN, vector<string> InAuthors, Date InPrintDate, Date InReleaseDate);
    Book(string InTitle, string InISBN, vector<string> InAuthors, Date InPrintDate, Date InReleaseDate, Date InApproveDate) 
    : Book(InTitle, InISBN, InAuthors, InPrintDate, InReleaseDate){SetApproveDate(InApproveDate);}

    string GetTitle() const;
    void SetTitle(string InTitle);

    string GetISBN() const;
    void SetISBN(string InISBN);

    vector<string> GetAuthors() const;
    void SetAuthors(vector<string> InAuthors);

    int GetPublishedID() const;

    Date GetPrintDate() const;
    void SetPrintDate(Date InPrintDate);
    void SetPrintDate(int InYear, int InMonth, int InDay);

    Date GetReleaseDate() const;
    void SetReleaseDate(Date InReleaseDate);
    void SetReleaseDate(int InYear, int InMonth, int InDay);

    Date GetApproveDate() const;
    void SetApproveDate(Date InApproveDate);
    void SetApproveDate(int InYear, int InMonth, int InDay);

    bool IsApproved() const;

    friend ostream& operator<<(ostream& os, const Book& InBook);
    friend istream& operator>>(istream& is, Book& OutBook);

};