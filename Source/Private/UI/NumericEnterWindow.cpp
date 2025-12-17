#include "UI/NumericEnterWindow.h"

void UI::NumericEnterWindow::Initiate(std::istream* InStreamPtr, std::ostream* OutStreamPtr)
{
    int EnteredNumber;
    (*OutStreamPtr) << Label;
    (*InStreamPtr) >> EnteredNumber;
    OnSelect.Broadcast(EnteredNumber);
}