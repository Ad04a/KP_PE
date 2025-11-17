//#include "Book.h"
//#include "Publisher.h"
//#include "System.h"

#include "Property.h"

#include <iostream>

#include <vector>
#include <string>

struct X {
    std::vector<std::string> v;
    void foo(std::vector<std::string> in) {
        v = in;  // triggers template instantiation
    }
};

int main()
{
    //CPPUtils::Property<std::string> s = CPPUtils::Property<std::string>();

    //CPPUtils::Property<int> i = CPPUtils::Property<int>();


    //s.Set(std::string("babag"));

    //i.Set(5);
    //i = 5;
    //std::cout<<s();

    //vector<std::string> autors;
    //autors.push_back("actor");

    //Book b1 = Book("Fotnite", "0123456789", autors, Date(20,2,20), Date(21,12,21));
    //Book b2 = Book("Fotnite", "0123456789", autors, Date(20,2,20), Date(21,12,21));
    //Book b3 = Book("Fotnite", "0123456789", autors, Date(20,2,20), Date(21,12,21));

   // b2.Title = "babag";

    //std::cout<<b1<<"\n"<<b2<<"\n"<<b3;

    std::string c = "babag";
    std::string b = c;
    b[3] = 'I';
    std::cout<<c<<"   -   "<<b<<std::endl;
    return 0;
}