#pragma once

#include <vector>
#include "Property.h"
#include "Exceptions/InvalidISBNException.h"
#include "Exceptions/InvalidPhoneException.h"
#include "Misc/Date.h"

//using namespace std;

class Book : PROPERTY_CLASS(Book), public DataUtils::IOutputable, public DataUtils::IStringifiable, public DataUtils::IInputable
{
    
private:
    int PublishId;

public:

    static bool Approve(Book& InBook);

    PROPERTY(std::string, Title, GET, PRIVATE_SET);
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
    PROPERTY(std::vector<std::string>, Authors, GET, PRIVATE_SET);
    PROPERTY(Date, PrintDate, GET, PRIVATE_SET);
    PROPERTY(Date, ReleaseDate, GET, PRIVATE_SET);
    PROPERTY(Date, ApproveDate, GET, PRIVATE_SET);

    Book(){}
    Book(std::string InTitle, std::string InISBN, std::vector<std::string> InAuthors, Date InPrintDate, Date InReleaseDate);
    Book(std::string InTitle, std::string InISBN, std::vector<std::string> InAuthors, Date InPrintDate, Date InReleaseDate, Date InApproveDate) 
    : Book(InTitle, InISBN, InAuthors, InPrintDate, InReleaseDate){ApproveDate = InApproveDate;}

    int GetPublishedID() const;

    bool IsApproved() const;

    virtual std::string ToString() const override;
    virtual std::ostream& Output(std::ostream& OutStream) const override;
    virtual std::istream& Input(std::istream& InStream) override;

};