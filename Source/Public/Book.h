#pragma once

#include <string>
#include <vector>
#include "Misc/Date.h"

using namespace std;

class Book
{

    private:

    //static int NumPublished;

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

    string GetTitle();
    void SetTitle(string InTitle);

    string GetISBN();
    void SetISBN(string InISBN);

    vector<string> GetAuthors();
    void SetAuthors(vector<string> InAuthors);

    int GetPublishedID();

    Date GetPrintDate();
    void SetPrintDate(Date InPrintDate);

    Date GetReleaseDate();
    void SetReleaseDate(Date InReleaseDate);

    Date GetApproveDate();
    void SetApproveDate(Date InApproveDate);

    bool IsApproved();
};