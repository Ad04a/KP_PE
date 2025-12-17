#pragma once

#include <vector>
#include "Property.h"
#include "Exceptions/InvalidISBNException.h"
#include "Exceptions/InvalidBookException.h"
#include "Exceptions/InvalidPhoneException.h"
#include "Misc/Date.h"

#include <iostream>
//using namespace std;

namespace Data
{
    class Book : PROPERTY_CLASS(Book), public DataUtils::IOutputable, public DataUtils::IStringifiable, public DataUtils::IInputable, public DataUtils::IEnterable
    {

    public:

        static bool Approve(Book& InBook);

        PROPERTY(std::string, Title, GET, PRIVATE_SET);
        PROPERTY(std::string, ISBN, GET, 
            PRIVATE_SET{
                if(VALUE.size() != 10 && VALUE.size() != 13) throw Exceptions::InvalidISBNException("ISBN must be 10 or 13 digits");
        
                for(unsigned int i=0; i<VALUE.size(); i++)
                {
                    if(VALUE[i]<'0' || VALUE[i]>'9') throw Exceptions::InvalidISBNException("ISBN must be 10 ot 13 DIGITS");
                }

                FIELD = VALUE;
            }
        );
        PROPERTY(std::vector<std::string>, Authors, GET, PRIVATE_SET);
        PROPERTY(DataUtils::Date, PrintDate, GET, PRIVATE_SET);
        PROPERTY(DataUtils::Date, ReleaseDate, GET, 
            PRIVATE_SET
            {
                if(VALUE.IsValid() == false) return;
                if(VALUE < SELF->PrintDate()) 
                    throw Exceptions::InvalidBookException
                    ("Release Date must be after print date(" + SELF->PrintDate().ToString()+")");
                FIELD = VALUE;
            }
        );
        PROPERTY(DataUtils::Date, ApproveDate, GET, 
            SET
            {
                if(SELF->IsApproved() || VALUE.IsValid() == false) return;
                if(VALUE < SELF->ReleaseDate()) 
                    throw Exceptions::InvalidBookException
                    ("Approve Date must be after release date("+SELF->ReleaseDate().ToString()+")");
                FIELD = VALUE;
            }
        );

        Book(){}
        Book(std::string InTitle, std::string InISBN, std::vector<std::string> InAuthors, DataUtils::Date InPrintDate, DataUtils::Date InReleaseDate);
        Book(std::string InTitle, std::string InISBN, std::vector<std::string> InAuthors, DataUtils::Date InPrintDate, DataUtils::Date InReleaseDate, DataUtils::Date InApproveDate) 
        : Book(InTitle, InISBN, InAuthors, InPrintDate, InReleaseDate){ApproveDate = InApproveDate;}

        bool IsApproved() const;

        virtual std::string ToString() const override;
        virtual std::ostream& Output(std::ostream& OutStream) const override;
        virtual std::istream& Input(std::istream& InStream) override;
        virtual void Enter(std::istream& InStream, std::ostream& OutStream) override;

        bool operator<(const Book& Other) const;

    };
}