#pragma once

#include "Interfaces/Initiatable.h"
#include "UI/MenuOption.h"

namespace UI
{
    class NumericEnterWindow : public IInitiatable, public MenuOptionImpl<void, int>
    {
    public:
        NumericEnterWindow() : NumericEnterWindow("Enter number: ") {}
        NumericEnterWindow(std::string InLabel) : MenuOptionImpl<void, int>(InLabel) {}
        virtual void Initiate(std::istream* InStreamPtr, std::ostream* OutStreamPtr) override;
    };
}