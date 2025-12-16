#pragma once

#include <iostream>

#include "UI/MenuOption.h"

namespace UI
{
    class StreamStringMenuOption : public MenuOptionImpl<void, std::istream*, std::ostream*, std::string> 
    {   
    private:
        std::istream* InStreamPtr;
        std::ostream* OutStreamPtr;
    public:  
        StreamStringMenuOption(std::istream* InInStream = &std::cin, std::ostream* InOutStream = &std::cout) : StreamStringMenuOption("Empty option", InInStream, InOutStream){}
        StreamStringMenuOption(std::string InLabel, std::istream* InInStream = &std::cin, std::ostream* InOutStream = &std::cout) : MenuOptionImpl<void, std::istream*, std::ostream*, std::string>(InLabel), InStreamPtr(InInStream), OutStreamPtr(InOutStream){}
        virtual void Select() override { OnSelect.Broadcast(InStreamPtr, OutStreamPtr, Label);}

    };
}

