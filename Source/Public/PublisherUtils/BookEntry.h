#pragma once

#include "Book.h"

#include "Exceptions/InvalidBookEntryException.h"


namespace PublisherUtils
{
    
    class BookEntry : PROPERTY_CLASS(BookEntry), public DataUtils::IOutputable, public DataUtils::IStringifiable, public DataUtils::IInputable, public DataUtils::IEnterable
    {
    
    public:
        BookEntry(){};
        BookEntry(Book InHeldBook, float InPrice);

        PROPERTY(Book, HeldBook, GET, PRIVATE_SET);
        PROPERTY(float, Price, GET, 
            PRIVATE_SET
            {
                if(VALUE <= -1) throw InvalidBookEntryException("Book's price must be >= 0");
                FIELD = VALUE;
            }
        );    
        
        virtual std::string ToString() const override;
        virtual std::ostream& Output(std::ostream& OutStream) const override;
        virtual std::istream& Input(std::istream& InStream) override;
        virtual void Enter(std::istream& InStream, std::ostream& OutStream) override;

        bool operator<(const BookEntry& Other) const;
    };

    
}