#pragma once

#include <regex>

#include "Exceptions/InvalidPhoneException.h"
#include "Interfaces/Initiatable.h"
#include "PublisherUtils/BookRegistry.h"

namespace Data
{
    class Publisher : PROPERTY_CLASS(Publisher), public DataUtils::IOutputable, public DataUtils::IStringifiable, public DataUtils::IInputable, public DataUtils::IEnterable, public UI::IInitiatable
    {

    public:

        PROPERTY(int, hui, GET{return 5;});

        PROPERTY(std::string, Name, GET, PRIVATE_SET);
        PROPERTY(std::string, Address, GET, PRIVATE_SET);
        PROPERTY(std::string, Phone, GET, 
            PRIVATE_SET
            {
                const std::regex bgPhoneRegex(R"(^(?:\+359|00359|0)(?:87|88|89|98|99|2|32|52|56|64|66)\d{7}$)");

                if(std::regex_match(VALUE, bgPhoneRegex) == false) throw Exceptions::InvalidPhoneException("Phone must be valid Bulgarian phone number");
            }
            FIELD = VALUE;
        );

        PROPERTY(PublisherUtils::BookRegistry, Books, GET, PRIVATE_SET);

        Publisher(){}
        Publisher(std::string InName, std::string InAddress, std::string InPhone);
        Publisher(std::string InName, std::string InAddress, std::string InPhone, PublisherUtils::BookRegistry InBooks) : Publisher(InName, InAddress, InPhone) {Books = InBooks;};


        virtual std::string ToString() const override;
        virtual std::ostream& Output(std::ostream& OutStream) const override;
        virtual std::istream& Input(std::istream& InStream) override;
        virtual void Enter(std::istream& InStream, std::ostream& OutStream) override;
        virtual void Initiate(std::istream* InStreamPtr, std::ostream* OutStreamPtr) override;
    };
}