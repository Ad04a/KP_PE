#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include "Property.h"

#include "Interfaces/Initiatable.h"
#include "UI/MenuOptions.h"

namespace UI
{
    class Menu : PROPERTY_CLASS(Menu), public Data::Utils::IStringifiable, public UI::IInitiatable
    {
    public:
        PROPERTY(std::string, Label, GET, SET);
        PROPERTY(std::vector<std::shared_ptr<MenuOption>>, Options, GET, SET);
        PROPERTY(Options::SimpleMenuOption, Back, GET, SET);

        Menu() : Menu("Empty Menu", {}, Options::SimpleMenuOption("Back")){}
        Menu(std::string InLabel) : Menu(InLabel, {}, Options::SimpleMenuOption("Back")){}
        Menu(std::string InLabel, Options::SimpleMenuOption InBack) : Menu(InLabel, {}, InBack){}
        Menu(std::string InLabel, std::vector<std::shared_ptr<MenuOption>> InOptions) : Menu(InLabel, InOptions, Options::SimpleMenuOption("Back")){}
        Menu(std::string InLabel, std::vector<std::shared_ptr<MenuOption>> InOptions, Options::SimpleMenuOption InBack);

        void Initiate(std::istream* InStreamPtr, std::ostream* OutStreamPtr) override;

        void ChooseOption(int OptionNum);

        virtual std::string ToString() const override;

    };
}