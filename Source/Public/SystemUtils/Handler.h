#pragma once

#include <iostream>
#include "Property.h"

#include "UI/Menu.h"

namespace SystemUtils
{
    class Handler : PROPERTY_CLASS(Handler)
    {
    public:

        PROPERTY(UI::Menu, HeldMenu, GET, PRIVATE_SET);
        
        Handler(std::string MenuLabel) : Handler(MenuLabel, UI::MenuOption("Back")){}
        Handler(std::string MenuLabel, UI::MenuOption InBack);

        virtual void Start(std::istream* InStream, std::ostream* OutStream);

    };
}