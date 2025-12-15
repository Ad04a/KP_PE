#include "SystemUtils/System.h"

#include <fstream>
#include <filesystem>
#include <windows.h>

#include "UI/MenuOption.h"
#include "Exceptions/FileException.h"

SystemUtils::System::System() : Handler("Main Menu", UI::MenuOption("Exit"))
{
    if (!std::filesystem::exists(IntermediateFolder())) std::filesystem::create_directory(IntermediateFolder());
    if (!std::filesystem::exists(PublisherFolder())) std::filesystem::create_directory(PublisherFolder());
    if (!std::filesystem::exists(PublisherEntryFile()))
    {
        std::ofstream PublisherEntry(PublisherEntryFile());
        if (!PublisherEntry) {
            throw FileException("Can not create file: " + PublisherEntryFile());
        }
        PublisherEntry<<"temp text";
        PublisherEntry.close();
    }

    //--------------------------Registry Menu options-----------------------------------
    RegistryManager.HeldMenu().Back().OnSelect().Add(&HeldMenu(), &UI::Menu::Initiate);
    //--------------------------Registry Menu options-----------------------------------

    //--------------------------Publisher Menu options-----------------------------------
    PublisherManager.HeldMenu().Back().OnSelect().Add(&HeldMenu(), &UI::Menu::Initiate);
    //--------------------------Publisher Menu options-----------------------------------

    //--------------------------Store Menu options-----------------------------------
    StoreManager.HeldMenu().Back().OnSelect().Add(&HeldMenu(), &UI::Menu::Initiate);
    //--------------------------Store Menu options-----------------------------------

    //--------------------------Main Menu options-----------------------------------
    UI::MenuOption PublisherMenuOption("Publisher Menu");
    PublisherMenuOption.OnSelect().Add<PublisherHandler>(&PublisherManager, &PublisherHandler::Start);
    UI::MenuOption RegistryMenuOption("Publisher Registry Menu");
    RegistryMenuOption.OnSelect().Add<RegistryHandler>(&RegistryManager, &RegistryHandler::Start);
    UI::MenuOption StoreMenuOption("Book Store Menu");
    StoreMenuOption.OnSelect().Add<BookStoreHandler>(&StoreManager, &BookStoreHandler::Start);

    HeldMenu().Options = {RegistryMenuOption, PublisherMenuOption, StoreMenuOption};
    //--------------------------Main Menu options-----------------------------------

}