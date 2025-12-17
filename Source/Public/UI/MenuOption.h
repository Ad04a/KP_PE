#pragma once

#include <iostream>

#include "Misc/Delegate.h"
#include "Interfaces/Misc/Stringifiable.h"

namespace UI
{

    class MenuOption : public DataUtils::IStringifiable
    {
    protected:
        std::string Label;
    public:
        MenuOption() : MenuOption("Empty option"){}
        MenuOption(std::string InLabel) : Label(InLabel){}

        virtual std::string ToString() const override {return Label;}
        virtual void Select(){};

    };

    template<typename ReturnType = void, typename... ParamTypes>
    class MenuOptionImpl : public MenuOption
    {
    public:   
        using MenuDelegateSignature = DataUtils::Delegate<ReturnType, ParamTypes...>;
        MenuDelegateSignature OnSelect;
        MenuOptionImpl() : MenuOptionImpl("Empty option"){}
        MenuOptionImpl(std::string InLabel): MenuOption(InLabel){}

    };
}

