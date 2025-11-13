//#include "Book.h"
//#include "Publisher.h"
//#include "System.h"

#include "Property.h"

#include <iostream>

int main()
{
    CPPUtils::Property<std::string> s = CPPUtils::Property<std::string>();

    s = "babag";

    std::cout<<s();

    //vector<std::string> autors;
    //autors.push_back("actor");

    //Book b1 = Book("Fotnite", "0123456789", autors, Date(20,2,20), Date(21,12,21));
    //Book b2 = Book("Fotnite", "0123456789", autors, Date(20,2,20), Date(21,12,21));
    //Book b3 = Book("Fotnite", "0123456789", autors, Date(20,2,20), Date(21,12,21));

   // b2.Title = "babag";

    //std::cout<<b1<<"\n"<<b2<<"\n"<<b3;

    return 0;
}