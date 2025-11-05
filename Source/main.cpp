#include "Public/Book.h"
#include "Public/Publisher.h"
#include "Public/System.h"

#include <iostream>

int main()
{
    vector<string> autors;
    autors.push_back("actor");
    Book b1 = Book("Fotnite", "asdsad", autors, Date(20,2,20), Date(21,2,21));

    std::cout << b1.IsApproved();

    return 0;
}