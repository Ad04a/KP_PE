#pragma once

#include "Interfaces/Initiatable.h"
#include "UI/MenuOption.h"

namespace UI
{
    class ConfirmationWindow : public IInitiatable, public MenuOptionImpl<void, bool>
    {
    public:
        ConfirmationWindow() : ConfirmationWindow("Are you sure? [Y/N]: ") {}
        ConfirmationWindow(std::string InLabel) : MenuOptionImpl<void, bool>(InLabel) {}
        virtual void Initiate(std::istream* InStreamPtr, std::ostream* OutStreamPtr) override;
    };
}