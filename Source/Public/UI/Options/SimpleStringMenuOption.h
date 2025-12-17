#pragma once

#include <iostream>

#include "UI/MenuOption.h"

namespace UI
{
    namespace Options
    {
        class SimpleStringMenuOption : public MenuOptionImpl<void, std::string> 
        {   

        public:  
            SimpleStringMenuOption() : SimpleStringMenuOption("Empty option"){}
            SimpleStringMenuOption(std::string InLabel) : MenuOptionImpl<void, std::string>(InLabel) {}
            virtual void Select() override { OnSelect.Broadcast(Label);}

        };
    }
}

