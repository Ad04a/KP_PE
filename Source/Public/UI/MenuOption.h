#pragma once

#include <iostream>
#include "Property.h"

#include "Misc/Delegate.h"
#include "Interfaces/Misc/Stringifiable.h"

namespace UI
{
    class MenuOption : PROPERTY_CLASS(MenuOption), public DataUtils::IStringifiable
    {   
    private:
        std::istream* InStream;
        std::ostream* OutStream;
    public:   
    
        PROPERTY(std::string, Label, GET, SET);
        using MenuDelegateSignature = Delegate<void, std::istream*, std::ostream*>;
        PROPERTY(MenuDelegateSignature, OnSelect, GET, PRIVATE_SET);

        MenuOption(std::istream* InInStream = &std::cin, std::ostream* InOutStream = &std::cout) : MenuOption("Empty option", InInStream, InOutStream){}
        MenuOption(std::string InLabel, std::istream* InInStream = &std::cin, std::ostream* InOutStream = &std::cout);
        void Select();

        virtual std::string ToString() const override;
    };
}

