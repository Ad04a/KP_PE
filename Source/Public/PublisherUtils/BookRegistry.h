#pragma once

#include <set>

#include "PublisherUtils/BookEntry.h"

namespace Data
{
    namespace PublisherUtils
    {
        class BookRegistry : PROPERTY_CLASS(BookRegistry), public DataUtils::IOutputable, public DataUtils::IStringifiable, public DataUtils::IInputable, public DataUtils::IEnterable
        {

        public:
            BookRegistry(){};
            BookRegistry(std::set<BookEntry> InRegistry);

            PROPERTY(std::set<BookEntry>, Registry, GET, PRIVATE_SET);
            
            virtual std::string ToString() const override;
            virtual std::ostream& Output(std::ostream& OutStream) const override;
            virtual std::istream& Input(std::istream& InStream) override;
            virtual void Enter(std::istream& InStream, std::ostream& OutStream) override;
        };

    }
}