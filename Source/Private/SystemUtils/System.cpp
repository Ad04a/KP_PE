#include "SystemUtils/System.h"

#include <filesystem>
#include <windows.h>

#include "UI/MenuOptions.h"
#include "UI/ProceedingWindow.h"
#include "UI/ConfirmationWindow.h"
#include "Exceptions/FileException.h"
#include "SystemUtils/Filepaths.h"

#include "Publisher.h"

SystemUtils::System::System(std::istream* InInStreamPtr, std::ostream* InOutStreamPtr)
{
    if (!std::filesystem::exists(SystemUtils::IntermediateFolder())) std::filesystem::create_directory(SystemUtils::IntermediateFolder());
    if (!std::filesystem::exists(SystemUtils::PublisherFolder())) std::filesystem::create_directory(SystemUtils::PublisherFolder());
    if (!std::filesystem::exists(SystemUtils::PublisherEntryFile()))
    {
        std::ofstream PublisherEntry(PublisherEntryFile());
        if (!PublisherEntry) {
            throw Exceptions::FileException("Can not create file: " + PublisherEntryFile());
        }
        PublisherEntry.close();
    }

    InStreamPtr = InInStreamPtr;
    OutStreamPtr = InOutStreamPtr;


    //--------------------------Main Menu options-----------------------------------
    UI::Options::SimpleMenuOption ShowPublishersOption("Show list of publishers");
    ShowPublishersOption.OnSelect.Add(this, &SystemUtils::System::OpenViewPublisherListMenu);
    UI::Options::SimpleMenuOption AddPublisherOption("Register new publisher");
    AddPublisherOption.OnSelect.Add(this, &SystemUtils::System::AddPublisher);
    UI::Options::SimpleMenuOption RemovePublisherOption("Unregister a publisher");
    RemovePublisherOption.OnSelect.Add(this, &SystemUtils::System::OpenRemovePublisherListMenu);
    UI::Options::SimpleMenuOption MakeOrderOption("Make an order from a publisher");
    MakeOrderOption.OnSelect.Add(this, &SystemUtils::System::OpenOrderPublisherListMenu);

    MainMenu.Options = {std::make_shared<UI::Options::SimpleMenuOption>(ShowPublishersOption), 
                        std::make_shared<UI::Options::SimpleMenuOption>(AddPublisherOption), 
                        std::make_shared<UI::Options::SimpleMenuOption>(RemovePublisherOption),
                        std::make_shared<UI::Options::SimpleMenuOption>(MakeOrderOption)};
    //--------------------------Main Menu options-----------------------------------

}

void SystemUtils::System::Start()
{
    UpdatePublisherList();
    OpenMainMenu();
}

void SystemUtils::System::UpdatePublisherList()
{
    std::ifstream PublisherFile(SystemUtils::PublisherEntryFile());
    PublisherList.clear();
    std::string TempString;
    while(std::getline(PublisherFile, TempString))
    {
        PublisherList.push_back(TempString);
    }
}

void SystemUtils::System::ShowPublisherCatalogue(std::string PublisherName)
{
    Data::Publisher LoadedPublisher;
    std::ifstream PublisherFile(SystemUtils::PublisherFolder() + PublisherName + ".txt");
    if(!PublisherFile) throw Exceptions::FileException("Publisher file not found: " + SystemUtils::PublisherFolder() + PublisherName + ".txt");
    PublisherFile>>LoadedPublisher;
    PublisherFile.close();

    (*OutStreamPtr)<<"\n\n"<<LoadedPublisher.ToString()<<"\n";
    UI::ProceedingWindow PW;
    PW.OnSelect.Add(this, &SystemUtils::System::OpenViewPublisherListMenu);
    PW.Initiate(InStreamPtr, OutStreamPtr);
}

void SystemUtils::System::AddPublisher()
{
    Data::Publisher NewPublisher;
    NewPublisher.Enter(*InStreamPtr, *OutStreamPtr);
    std::ofstream PublisherFile(SystemUtils::PublisherEntryFile(), std::ios::app);

    std::ifstream file(SystemUtils::PublisherEntryFile());

    if(std::find(PublisherList.begin(), PublisherList.end(), NewPublisher.Name()) != PublisherList.end()) 
    {
        
        UI::ConfirmationWindow CW("\nPublisher " + NewPublisher.Name() + " already exists! Do you want to overwrite it? [Y/N]: ");
        class TempConferm
        {
        public:
            void SetConfirmed(bool InConfirmed) { Confirmed = InConfirmed; }
            bool Confirmed = false;
        };
        TempConferm Overwrite;
        CW.OnSelect.Add(&Overwrite, &TempConferm::SetConfirmed);
        CW.Initiate(InStreamPtr, OutStreamPtr);

        if(Overwrite.Confirmed == false)
        {
            CW = UI::ConfirmationWindow("\nDo you want to rename the current configuration and save it with the new name? [Y/N]: ");
            CW.OnSelect.Add(&Overwrite, &TempConferm::SetConfirmed);
            CW.Initiate(InStreamPtr, OutStreamPtr);
            if(Overwrite.Confirmed)
            {
                std::string OldName = NewPublisher.Name();
                (*OutStreamPtr)<<"\nEnter new name for publisher: ";
                std::string NewName;
                (*InStreamPtr).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(*InStreamPtr, NewName);
                while(std::find(PublisherList.begin(), PublisherList.end(), NewName) != PublisherList.end())
                {
                    (*OutStreamPtr)<<"\nPublisher " + NewName + " already exists! Please enter a different name: ";
                    std::getline(*InStreamPtr, NewName);
                }
                NewPublisher.Name() = NewName;
            }
            else
            {
                (*OutStreamPtr)<<"\nPublisher configuration was not saved.\n";
                OpenMainMenu();
            }
        }

    }
    else
    {
        PublisherFile<<NewPublisher.Name()<<"\n";
        PublisherFile.close();
    }

    std::ofstream NewPublisherFile(SystemUtils::PublisherFolder() + NewPublisher.Name() + ".txt");
    NewPublisherFile<<NewPublisher;
    NewPublisherFile.close();

    UpdatePublisherList();

    OpenMainMenu();
}

void SystemUtils::System::RemovePublisher(std::string PublisherName)
{
    class TempConferm
    {
    public:
        void SetConfirmed(bool InConfirmed) { Confirmed = InConfirmed; }
        bool Confirmed = false;
    };

    TempConferm Temp;
    UI::ConfirmationWindow CW("\nAre you sure you want to remove publisher " + PublisherName + "? [Y/N]: ");
    CW.OnSelect.Add(&Temp, &TempConferm::SetConfirmed);
    CW.Initiate(InStreamPtr, OutStreamPtr);

    if(Temp.Confirmed)
    {
        std::filesystem::remove(SystemUtils::PublisherFolder() + PublisherName + ".txt");

        std::ofstream PublisherFile(SystemUtils::PublisherEntryFile());
        for(auto It = PublisherList.begin(); It != PublisherList.end(); It++)
        {
            if(*It != PublisherName)
            {
                PublisherFile<<*It<<"\n";
            }
        }
        PublisherFile.close();
        UpdatePublisherList();
    }
    OpenRemovePublisherListMenu();
}

void SystemUtils::System::MakeOrderFromPublisher(std::string PublisherName)
{
    Data::Publisher LoadedPublisher;
    std::ifstream PublisherFile(SystemUtils::PublisherFolder() + PublisherName + ".txt");
    if(!PublisherFile) throw Exceptions::FileException("Publisher file not found: " + SystemUtils::PublisherFolder() + PublisherName + ".txt");
    PublisherFile>>LoadedPublisher;
    PublisherFile.close();

    LoadedPublisher.Initiate(InStreamPtr, OutStreamPtr);

    OpenMainMenu();
}

void SystemUtils::System::OpenMainMenu() 
{ 
    MainMenu.Initiate(InStreamPtr, OutStreamPtr); 
}

void SystemUtils::System::OpenRemovePublisherListMenu()
{
    ConfigurePublisherListMenu(RemovePublisherAction);
    PublisherListMenu.Initiate(InStreamPtr, OutStreamPtr); 
}

void SystemUtils::System::OpenViewPublisherListMenu()
{
    ConfigurePublisherListMenu(PublisherShowCatalogAction);
    PublisherListMenu.Initiate(InStreamPtr, OutStreamPtr); 
}

void SystemUtils::System::OpenOrderPublisherListMenu()
{
    ConfigurePublisherListMenu(OrderFromPublisherAction);
    PublisherListMenu.Initiate(InStreamPtr, OutStreamPtr); 
}


void SystemUtils::System::ConfigurePublisherListMenu(PublisherListAction Action)
{
    std::vector<std::shared_ptr<UI::MenuOption>> Options;
    for(std::string PublisherName : PublisherList)
    {
        auto NewOption = std::make_shared<UI::Options::SimpleStringMenuOption>(PublisherName);
        NewOption->OnSelect.Add(this, GetPublisherSelectMethodPtr(Action));
        Options.push_back(NewOption);
    }
    PublisherListMenu.Label = GetPublisherSelectLabel(Action);
    PublisherListMenu.Options = Options;
    PublisherListMenu.Back = UI::Options::SimpleMenuOption(GetPublisherMenuBackOptionLabel(Action));
    PublisherListMenu.Back().OnSelect.Add(this, &SystemUtils::System::OpenMainMenu);
}

std::string SystemUtils::System::GetPublisherMenuBackOptionLabel(PublisherListAction Action)
{
    switch (Action)
    {
    case PublisherShowCatalogAction:
        return "Back";
    default:
        return "Cancel";
    }
}

std::string SystemUtils::System::GetPublisherSelectLabel(PublisherListAction Action)
{
    switch (Action)
    {
    case PublisherShowCatalogAction:
        return "View Catalogue";
    case RemovePublisherAction:
        return "Unregister";
    case OrderFromPublisherAction:
        return "Order From Publisher";
    default:
        return "Unknown Action";
    }
}

SystemUtils::System::PublisherSelectMethodPtrType SystemUtils::System::GetPublisherSelectMethodPtr(PublisherListAction Action)
{
    switch (Action)
    {
    case PublisherShowCatalogAction:
        return &SystemUtils::System::ShowPublisherCatalogue;
    case RemovePublisherAction:
        return &SystemUtils::System::RemovePublisher;
    case OrderFromPublisherAction:
        return &SystemUtils::System::MakeOrderFromPublisher;
    default:
        return nullptr;
    }
}