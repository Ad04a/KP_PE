#include "UI/MenuOption.h"

UI::MenuOption::MenuOption(std::string InLabel)
{
    Label = InLabel;
}

std::string UI::MenuOption::ToString() const
{
    return Label();
}