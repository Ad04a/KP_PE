#pragma once

#include <vector>
#include <iostream>

#include "UI/MenuOption.h"

namespace UI
{
    class Menu : PROPERTY_CLASS(Menu), public DataUtils::IStringifiable
    {
    public:
        PROPERTY(std::string, Label, GET, PRIVATE_SET);
        PROPERTY(std::vector<MenuOption>, Options, GET, SET);
        PROPERTY(MenuOption, Back, GET, PRIVATE_SET);

        Menu() : Menu("Empty Menu", {}, MenuOption("Back")){}
        Menu(std::string InLabel) : Menu(InLabel, {}, MenuOption("Back")){}
        Menu(std::string InLabel, MenuOption InBack) : Menu(InLabel, {}, InBack){}
        Menu(std::string InLabel, std::vector<MenuOption> InOptions) : Menu(InLabel, InOptions, MenuOption("Back")){}
        Menu(std::string InLabel, std::vector<MenuOption> InOptions, MenuOption InBack);

        void Initiate(std::istream* InStreamPtr, std::ostream* OutStreamPtr);

        void ChooseOption(int OptionNum);

        virtual std::string ToString() const override;

    };
}