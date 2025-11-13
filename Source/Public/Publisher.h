#pragma once

#include <string>
#include <map>

#include "Book.h"

using namespace std;

class Publisher
{

    private:

    string Name;
    string Address;
    string Phone;
    //vector<Book, float> Books;

    public:

    Publisher(string InName, string InAddress, string InPhone);
    //Publisher(string InName, string InAddress, string InPhone, map<Book,float> Books) : Publisher(InName, InAddress, InPhone) {SetBooks(InBooks);};

    string GetName();
    void SetName();
    string GetAddress();
    void SetAddress();
    string GetPhone();
    void SetPhone();
    map<Book, float> GetBooks();
    //void SetBooks(map<Book, int> InBooks);
    void AddBook(Book InBook, float InPrice);
    void ClearBooks();

    float MakeOrder();

};