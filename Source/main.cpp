//#include "Book.h"
#include "Publisher.h"
//#include "System.h"

#include "Property.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string IntermediateFolder = "./Intermediate/";
    if (!std::filesystem::exists(IntermediateFolder)) std::filesystem::create_directory(IntermediateFolder);

    //b1.Enter(std::cin, std::cout);

    Publisher br, br2;
    br.Enter(std::cin, std::cout);

    std::ofstream f(IntermediateFolder + "input.txt");
    f<<br;
    f.close();

    std::ifstream file(IntermediateFolder + "input.txt");
    if (!file) {
        std::cerr << "Error: cannot open file\n";
    }
    
    file>>br2;
    file.close();

    std::cout<<br<<"\nRegistry after read ----- \n"<<br2<<"\n\n\n"<<br2.ToString();

    //Publisher pub = Publisher("Publisher", "Nqkude v sofia", "0888666495");

    return 0;
}