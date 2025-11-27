#pragma once

#include <string>
#include <vector>
#include "Property.h"
#include "Exceptions/InvalidISBNException.h"
#include "Exceptions/InvalidPhoneException.h"
#include "Misc/Date.h"

//using namespace std;

class Book
{
    PROPERTY_CLASS(Book)
private:

    //static int NumPublished;
    std::string Title;
    std::vector<std::string> Authors;
    int PublishId;
    Date PrintDate;
    Date ReleaseDate;
    Date ApproveDate;

public:
    PROPERTY(std::string, ISBN, GET, 
        PRIVATE_SET{
            if(VALUE.size() != 10 && VALUE.size() != 13) throw InvalidISBNException("ISBN must be between 10 and 13 digits");
    
            for(unsigned int i=0; i<VALUE.size(); i++)
            {
                if(VALUE[i]<'0' || VALUE[i]>'9') throw InvalidISBNException("ISBN must be between 10 and 13 DIGITS");
            }

            FIELD = VALUE;
        }
    );
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