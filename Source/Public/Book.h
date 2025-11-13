#pragma once

#include <string>
#include <vector>
//#include "Property.h"
#include "Misc/Date.h"

//using namespace std;

class Book
{

private:

    //static int NumPublished;

    std::string ISBN;
    std::string Title;
    std::vector<std::string> Authors;
    int PublishId;
    Date PrintDate;
    Date ReleaseDate;
    Date ApproveDate;

public:

    //CPPUtils::Property<std::string> Title;
    //CPPUtils::Property<std::string> ISBN;

    Book();
    Book(std::string InTitle, std::string InISBN, std::vector<std::string> InAuthors, Date InPrintDate, Date InReleaseDate);
    Book(std::string InTitle, std::string InISBN, std::vector<std::string> InAuthors, Date InPrintDate, Date InReleaseDate, Date InApproveDate) 
    : Book(InTitle, InISBN, InAuthors, InPrintDate, InReleaseDate){SetApproveDate(InApproveDate);}

    void SetISBN(std::string InISBN);

    //std::vector<std::string> GetAuthors() const;
    void SetAuthors(std::vector<std::string> InAuthors);

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
    /*
    friend ostream& operator<<(ostream& os, const Book& InBook);
    friend istream& operator>>(istream& is, Book& OutBook);*/

};