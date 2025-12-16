#include "UI/ConfirmationWindow.h"

#include <limits>

void UI::ConfirmationWindow::Initiate(std::istream* InStreamPtr, std::ostream* OutStreamPtr)
{
    std::istream& InStream = *InStreamPtr;
    std::ostream& OutStream = *OutStreamPtr;

    char UserInput;
    OutStream<<Label;
    InStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    InStream>>UserInput;
    if(UserInput >= 'a') UserInput-=('a' - 'A');
    while(UserInput!='Y' && UserInput!='N')
    {
        OutStream<<"Only Y and N: ";
        InStream >> UserInput;
    }
    OnSelect.Broadcast(UserInput == 'Y');
}