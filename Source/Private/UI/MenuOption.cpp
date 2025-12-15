#include "UI/MenuOption.h"

UI::MenuOption::MenuOption(std::string InLabel, std::istream* InInStream, std::ostream* InOutStream) : InStream(InInStream), OutStream(InOutStream)
{
    Label = InLabel;
}

void UI::MenuOption::Select()
{
    OnSelect().Broadcast(InStream, OutStream);
}

std::string UI::MenuOption::ToString() const
{
    return Label();
}