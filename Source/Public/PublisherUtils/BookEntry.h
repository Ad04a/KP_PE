#pragma once

#include "Book.h"

class BookRegistry;

namespace PublisherUtils
{
    
    class BookEntry : PROPERTY_CLASS(BookEntry), public DataUtils::IOutputable, public DataUtils::IStringifiable, public DataUtils::IInputable, public DataUtils::IEnterable
    {
        friend BookRegistry;

    public:
        PROPERTY(Book, HeldBook, GET, PRIVATE_SET);
        PROPERTY(float, Price, GET, PRIVATE_SET);    

        BookEntry(Book InHeldBook, float InPrice);
        
        virtual std::string ToString() const override;
        virtual std::ostream& Output(std::ostream& OutStream) const override;
        virtual std::istream& Input(std::istream& InStream) override;
        virtual void Enter(std::istream& InStream, std::ostream& OutStream) override;

        bool operator<(const BookEntry& Other) const;
    };

    
}