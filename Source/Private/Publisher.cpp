#include "Publisher.h"

#include <limits>
#include <cstdlib>

#include "UI/ProceedingWindow.h"
#include "Exceptions/InvalidPublisherException.h"

Data::Publisher::Publisher(std::string InName, std::string InAddress, std::string InPhone)
{
    Name = InName;
    Address = InAddress;
    Phone = InPhone;
}


void Data::Publisher::Initiate(std::istream* InStreamPtr, std::ostream* OutStreamPtr)
{
    std::istream& InStream = *InStreamPtr;
    std::ostream& OutStream = *OutStreamPtr;
    while ((InStream.get()) != '\n');
    std::map<Data::PublisherUtils::BookEntry, int> OrderBooks;
    while (true)
    {
        system("cls");
        OutStream<<"Current Order Books:\n";
        for (const auto& OrderEntry : OrderBooks)
        {
            OutStream<<" - " + OrderEntry.first.HeldBook().Title() + ": " + std::to_string(OrderEntry.second) + " copies\n";
        }
        OutStream<<"Total price so far: ";
        float TotalPrice = 0.0f;
        for (const auto& OrderEntry : OrderBooks)
        {
            TotalPrice += OrderEntry.first.Price() * OrderEntry.second;
        }
        OutStream<<std::to_string(TotalPrice)<<"\n\nPublisher: " + Name() + "'s " << Books().ToString();
        OutStream<<"\n Which book do you want to order from " + Name() + "? (Enter 'exit' to finish the order): ";
        std::string BookISBN;
        std::getline(InStream, BookISBN);
        if(BookISBN == "exit") break;

        auto It = std::find_if(Books().Registry().begin(), Books().Registry().end(), [&BookISBN](const PublisherUtils::BookEntry& Entry) {
            return Entry.HeldBook().ISBN() == BookISBN;
        });

        if(It == Books().Registry().end())
        {
            OutStream<<"ISBN \"" + BookISBN + "\" not found in publisher's catalogue. Please enter a valid book title or 'exit' to finish the order\n";
            UI::ProceedingWindow PW;
            PW.Initiate(InStreamPtr, OutStreamPtr);
            continue;
        }

        OutStream<<"Book \"" + BookISBN + "\" found with price " + std::to_string(It->Price()) + ". How many copies do you want to order?: ";
        int Quantity;
        InStream>>Quantity;
        while ((InStream.get()) != '\n');
        OrderBooks[*It] += Quantity;
    
    }
}


std::string Data::Publisher::ToString() const
{
    return "Publisher: " + Name() + "\n - Address: " + Address() + "\n - Phone: " + Phone() + "\n - " + Books().ToString();
}

std::ostream& Data::Publisher::Output(std::ostream& OutStream) const
{
    OutStream<<"P "<<Name().size()<<" "<<Name()<<" "<<Address().size()<<" "<<Address()<<" "<<Phone().size()<<" "<<Phone()<<" "<<Books();
    return OutStream;
}

std::istream& Data::Publisher::Input(std::istream& InStream)
{
    char ID;
    InStream>>ID;
    if(ID != 'P') throw Exceptions::InvalidPublisherException("Invalid data format");

    int ReadLenght;
    InStream >> ReadLenght>>std::ws;
    char PublisherName[100];
    InStream.read(PublisherName, ReadLenght);
    PublisherName[ReadLenght] = '\0';
    Name = std::string(PublisherName);
    
    {
    InStream >> ReadLenght>>std::ws;
    char TempAddress[1000];
    InStream.read(TempAddress, ReadLenght);
    TempAddress[ReadLenght] = '\0';
    Address = std::string(TempAddress);
    }

    InStream >> ReadLenght>>std::ws;
    char TempPhone[16];
    InStream.read(TempPhone, ReadLenght);
    TempPhone[ReadLenght] = '\0';
    Phone = std::string(TempPhone);

    InStream>>Books();

    return InStream;
}

void Data::Publisher::Enter(std::istream& InStream, std::ostream& OutStream)
{
    OutStream<<"Enter Publisher's name: ";
    InStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(InStream, Name());

    OutStream<<"Enter Publisher's Address: ";
    std::getline(InStream, Address());

    std::string TempPhone;
    while(true)
    {
        try
        {
            OutStream<<"Enter publisher's phone: ";
            std::getline(InStream, TempPhone);
            Phone = TempPhone;
        }
        catch(const std::runtime_error& Error)
        {   
            OutStream<<Error.what()<<"\n"; continue;
        } 
        break;   
    }

    Books().Enter(InStream, OutStream);
}