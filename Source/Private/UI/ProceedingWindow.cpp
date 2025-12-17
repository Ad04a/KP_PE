#include "UI/ProceedingWindow.h"

#include <limits>

void UI::ProceedingWindow::Initiate(std::istream* InStreamPtr, std::ostream* OutStreamPtr)
{
    std::istream& InStream = *InStreamPtr;
    std::ostream& OutStream = *OutStreamPtr;

    std::string UserInput;
    InStream.sync();
    OutStream<<Label;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    OnSelect.Broadcast();
}