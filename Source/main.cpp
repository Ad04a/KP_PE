
#include "Publisher.h"

//#include "Property.h"
#include "SystemUtils/System.h"
//#include "SystemUtils/SystemHandlers.h"

#include <iostream>
//#include <vector>
//#include <string>

//#include "UI/Menu.h"
//#include "Misc/Delegate.h"

void EnterPublisher(int Num)
{
    std::cout<<"Num: "<<Num;
}

void RegisterNewPublisher(int Num)
{
    for(int i=0;i<Num;i++)
    {
        std::cout<<" - ";
    }
}

void HandlePublisherState(std::string PublisherName, std::istream& InStream, std::ostream& OutStream)
{
    /*if (!std::filesystem::exists(PublisherFolder + PublisherName + ".txt"))
    {
        std::cout<<"Publisher: "+PublisherName+" does not exist! Do you wish to crerate it (Y/N)";
        unsigned char Approve;
        InStream >> Approve;
        if(Approve >= 'a') Approve-=('a' - 'A');
        while(Approve!='Y' && Approve!='N')
        {
            OutStream<<"Only Y and N: ";
            InStream >> Approve;
        }
    } 
    std::cout<<PublisherName;*/
}

int main()
{
    //UI::Menu MainMenu("Main Menu", UI::StreamMenuOption("Exit"));

    //MainMenu.Initiate(&std::cin, &std::cout);

    SystemUtils::System ManaginSystem(&std::cin, &std::cout);
    ManaginSystem.Start();


    //b1.Enter(std::cin, std::cout);

    //Publisher br, br2;
    //br.Enter(std::cin, std::cout);

    /*std::ofstream f(IntermediateFolder + "input.txt");
    //f<<br;
    f.close();

    std::ifstream file(IntermediateFolder + "input.txt");
    if (!file) {
        std::cerr << "Error: cannot open file\n";
    }
    
    //file>>br2;
    file.close();

    std::cout<<br<<"\nRegistry after read ----- \n"<<br2<<"\n\n\n"<<br2.ToString();

    //Publisher pub = Publisher("Publisher", "Nqkude v sofia", "0888666495");*/

    return 0;
}