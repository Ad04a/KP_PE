#pragma once

#include <iostream>

#include "UI/MenuOption.h"

namespace UI
{
    namespace Options
    {
        class SimpleMenuOption : public MenuOptionImpl<void> 
        {   
        public:  
            SimpleMenuOption() : SimpleMenuOption("Empty option"){}
            SimpleMenuOption(std::string InLabel) : MenuOptionImpl<void>(InLabel) {}
            virtual void Select() override { OnSelect.Broadcast();}

        };
    }
}

