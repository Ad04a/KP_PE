#pragma once

#include <string>
#include <vector>
#include "Property.h"

#include "UI/Menu.h"

namespace SystemUtils
{
    class System
    {

        enum PublisherListAction
        {
            PublisherShowCatalogAction,
            RemovePublisherAction,
            EditPublisherAction,
            OrderFromPublisherAction,
        };

    private:
        std::vector<std::string> PublisherList;

        std::istream* InStreamPtr;
        std::ostream* OutStreamPtr;

        UI::Menu MainMenu = UI::Menu("Main Menu", UI::SimpleMenuOption("Exit"));
        void OpenMainMenu();

        UI::Menu PublisherListMenu;
        void OpenRemovePublisherListMenu();
        void OpenViewPublisherListMenu();
        void ConfigurePublisherListMenu(PublisherListAction Action);

        void UpdatePublisherList();

    public:              
        System(std::istream* InInStreamPtr, std::ostream* InOutStreamPtr);

        void ShowPublisherList();
        void ShowPublisherCatalogue(std::string PublisherName);
        void AddPublisher();
        void RemovePublisher(std::string PublisherName);

        void Start();
    };
}

