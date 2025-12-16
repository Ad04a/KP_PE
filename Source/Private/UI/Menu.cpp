#include "UI/Menu.h"

#include <cstdlib>

UI::Menu::Menu(std::string InLabel, std::vector<std::shared_ptr<MenuOption>> InOptions, SimpleMenuOption InBack)
{
    Label = InLabel;
    Options = InOptions;
    Back = InBack;
}

void UI::Menu::Initiate(std::istream* InStreamPtr, std::ostream* OutStreamPtr)
{
    std::istream& InStream = *InStreamPtr;
    std::ostream& OutStream = *OutStreamPtr;

    system("cls");

    OutStream<<ToString();
    OutStream<<"Enter option num: ";
    size_t OptionNum;
    InStream>>OptionNum;
    while(OptionNum<0 || OptionNum>Options().size())
    {
        OutStream<<"Options are between 0 and "<<Options().size()<<": ";
        InStream>>OptionNum;
    }
    ChooseOption(OptionNum);
}

void UI::Menu::ChooseOption(int OptionNum)
{
    if(OptionNum == 0) 
    {
        Back().Select();
        return;
    }
    OptionNum-=1;
    Options()[OptionNum]->Select();

}

std::string UI::Menu::ToString() const
{
    std::string TempString = Label() +":\n";
    for(size_t i=0; i<Options().size(); i++)
    {
        TempString += "[" + std::to_string(i+1)+ "]" + Options()[i]->ToString() + "\n";
    }
    TempString += "[0]" + Back().ToString() + "\n";
    return TempString;
};