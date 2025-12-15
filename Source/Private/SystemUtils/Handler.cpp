#include "SystemUtils/Handler.h"

SystemUtils::Handler::Handler(std::string MenuLabel, UI::MenuOption InBack)
{
    HeldMenu = UI::Menu(MenuLabel, InBack);
}

void SystemUtils::Handler::Start(std::istream* InStream, std::ostream* OutStream)
{
    HeldMenu().Initiate(InStream, OutStream);
}