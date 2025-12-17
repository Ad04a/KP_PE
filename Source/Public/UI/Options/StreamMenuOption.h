#pragma once

#include <iostream>

#include "UI/MenuOption.h"

namespace UI
{
    namespace Options
    {
        class StreamMenuOption : public MenuOptionImpl<void, std::istream*, std::ostream*> 
        {   
        private:
            std::istream* InStreamPtr;
            std::ostream* OutStreamPtr;
        public:  
            StreamMenuOption(std::istream* InInStream = &std::cin, std::ostream* InOutStream = &std::cout) : StreamMenuOption("Empty option", InInStream, InOutStream){}
            StreamMenuOption(std::string InLabel, std::istream* InInStream = &std::cin, std::ostream* InOutStream = &std::cout) : MenuOptionImpl<void, std::istream*, std::ostream*>(InLabel), InStreamPtr(InInStream), OutStreamPtr(InOutStream){}
            virtual void Select() override { OnSelect.Broadcast(InStreamPtr, OutStreamPtr);}

        };
    }
}

