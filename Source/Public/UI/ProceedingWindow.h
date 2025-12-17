#pragma once

#include "Interfaces/Initiatable.h"
#include "UI/MenuOption.h"

namespace UI
{
    class ProceedingWindow : public UI::IInitiatable, public MenuOptionImpl<void>
    {
    public:
        ProceedingWindow() : ProceedingWindow("Press anything to continue...") {}
        ProceedingWindow(std::string InLabel) : MenuOptionImpl<void>(InLabel) {}
        virtual void Initiate(std::istream* InStreamPtr, std::ostream* OutStreamPtr) override;
    };
}