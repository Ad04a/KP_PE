#pragma once

#include "Property.h"

#include "Interfaces/Misc/Stringifiable.h"

namespace UI
{
    //template< typename R = void, typename... Args>
    class MenuOption : PROPERTY_CLASS(MenuOption), public DataUtils::IStringifiable
    {
    private:
        

    public:   
    
        PROPERTY(std::string, Label, GET, SET);
    
        MenuOption() : MenuOption("Empty option"){}
        MenuOption(std::string InLabel);
        void Select();

        virtual std::string ToString() const override;
    };
}

