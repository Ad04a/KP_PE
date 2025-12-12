#include "Book.h"
//#include "Publisher.h"
//#include "System.h"

#include "Property.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <vector>
#include <string>

int main()
{

    std::string c = "babag";
    std::string b = c;
    b[3] = 'I';
    std::cout<<c<<"   -   "<<b<<std::endl;

    Book b1("Fortnite", "1236667770", std::vector<std::string>{"Bay Blagoi", "May", "Jay"}, Date(35,2,2), Date(67,6,7), Date());
    Book b2;
    //b1.ISBN = "674206d214";
    //std::cout<<"ISBN: "<<b1.ISBN();
    std::cout<<"\n"<<b1.ToString() << "\n - \n";

    std::cout<<b1 << "\n - \n";

    //Book::Approve(b1);

    std::cout<<b1 << "\n - \n\n\n";

    Date d(6767, 6, 7), d2;

    std::string IntermediateFolder = "./Intermediate/";
    if (!std::filesystem::exists(IntermediateFolder)) std::filesystem::create_directory(IntermediateFolder);

    b1.Enter(std::cin, std::cout);

    std::ofstream f(IntermediateFolder + "input.txt");
    f<<b1;
    //f<<d;
    f.close();

    std::ifstream file(IntermediateFolder + "input.txt");
    if (!file) {
        std::cerr << "Error: cannot open file\n";
    }
    //cin>>b2;
    file>>b2;
    std::cout<<b1<<"\nBook2 ----- \n"<<b2;

    /*file>>d2;

    std::cout<<d<<"\n-\n"<<d2;*/

    file.close();


    return 0;
}