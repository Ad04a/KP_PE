#include "SystemUtils/Handlers/RegistryHandler.h"

SystemUtils::RegistryHandler::RegistryHandler() : Handler("Publisher Registry Menu")
{
    UI::MenuOption ShowPublishersOption("Show list of publishers");
    UI::MenuOption AddPublisherOption("Register new publisher");
    UI::MenuOption RemovePublisherOption("Unregister a publisher");
    HeldMenu().Options = {ShowPublishersOption, AddPublisherOption, RemovePublisherOption};
}