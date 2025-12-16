#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include "Property.h"

#include "Interfaces/Initiatable.h"
#include "UI/MenuOptions.h"

namespace UI
{
    class Menu : PROPERTY_CLASS(Menu), public DataUtils::IStringifiable, public IInitiatable
    {
    public:
        PROPERTY(std::string, Label, GET, SET);
        PROPERTY(std::vector<std::shared_ptr<MenuOption>>, Options, GET, SET);
        PROPERTY(SimpleMenuOption, Back, GET, SET);

        Menu() : Menu("Empty Menu", {}, SimpleMenuOption("Back")){}
        Menu(std::string InLabel) : Menu(InLabel, {}, SimpleMenuOption("Back")){}
        Menu(std::string InLabel, SimpleMenuOption InBack) : Menu(InLabel, {}, InBack){}
        Menu(std::string InLabel, std::vector<std::shared_ptr<MenuOption>> InOptions) : Menu(InLabel, InOptions, SimpleMenuOption("Back")){}
        Menu(std::string InLabel, std::vector<std::shared_ptr<MenuOption>> InOptions, SimpleMenuOption InBack);

        void Initiate(std::istream* InStreamPtr, std::ostream* OutStreamPtr) override;

        void ChooseOption(int OptionNum);

        virtual std::string ToString() const override;

    };
}