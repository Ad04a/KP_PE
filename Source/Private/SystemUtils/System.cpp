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
            throw FileException("Can not create file: " + PublisherEntryFile());
        }
        PublisherEntry.close();
    }

    InStreamPtr = InInStreamPtr;
    OutStreamPtr = InOutStreamPtr;


    //--------------------------Main Menu options-----------------------------------
    UI::SimpleMenuOption ShowPublishersOption("Show list of publishers");
    ShowPublishersOption.OnSelect.Add(this, &SystemUtils::System::OpenViewPublisherListMenu);
    UI::SimpleMenuOption AddPublisherOption("Register new publisher");
    AddPublisherOption.OnSelect.Add(this, &SystemUtils::System::AddPublisher);
    UI::SimpleMenuOption RemovePublisherOption("Unregister a publisher");
    RemovePublisherOption.OnSelect.Add(this, &SystemUtils::System::OpenRemovePublisherListMenu);
    UI::SimpleMenuOption EditPublisherOption("Edit a publisher");
    UI::SimpleMenuOption MakeOrderOption("Make an order from a publisher");

    MainMenu.Options = {std::make_shared<UI::SimpleMenuOption>(ShowPublishersOption), 
                        std::make_shared<UI::SimpleMenuOption>(AddPublisherOption), 
                        std::make_shared<UI::SimpleMenuOption>(RemovePublisherOption),
                        std::make_shared<UI::SimpleMenuOption>(EditPublisherOption),
                        std::make_shared<UI::SimpleMenuOption>(MakeOrderOption)};
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
    Publisher LoadedPublisher;
    std::ifstream PublisherFile(SystemUtils::PublisherFolder() + PublisherName + ".txt");
    if(!PublisherFile) throw FileException("Publisher file not found: " + SystemUtils::PublisherFolder() + PublisherName + ".txt");
    PublisherFile>>LoadedPublisher;
    PublisherFile.close();

    (*OutStreamPtr)<<"\n\n"<<LoadedPublisher.ToString()<<"\n";
    UI::ProceedingWindow PW;
    PW.OnSelect.Add(this, &SystemUtils::System::OpenViewPublisherListMenu);
    PW.Initiate(InStreamPtr, OutStreamPtr);
}

void SystemUtils::System::AddPublisher()
{
    Publisher NewPublisher;
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

void SystemUtils::System::ConfigurePublisherListMenu(PublisherListAction Action)
{
    std::vector<std::shared_ptr<UI::MenuOption>> Options;
    for(std::string PublisherName : PublisherList)
    {
        auto NewOption = std::make_shared<UI::SimpleStringMenuOption>(PublisherName);
        NewOption->OnSelect.Add(this, (Action == PublisherShowCatalogAction) ? &SystemUtils::System::ShowPublisherCatalogue : &SystemUtils::System::RemovePublisher);
        Options.push_back(NewOption);
    }
    PublisherListMenu.Label = (Action == PublisherShowCatalogAction) ? "View Publisher Catalogue" : "Unregister Publisher";
    PublisherListMenu.Options = Options;
    PublisherListMenu.Back = UI::SimpleMenuOption((Action == PublisherShowCatalogAction) ?"Back" : "Cancel");
    PublisherListMenu.Back().OnSelect.Add(this, &SystemUtils::System::OpenMainMenu);
}