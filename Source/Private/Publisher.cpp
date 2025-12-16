#include "Publisher.h"

#include <limits>

#include "Exceptions/InvalidPublisherException.h"

Publisher::Publisher(std::string InName, std::string InAddress, std::string InPhone)
{
    Name = InName;
    Address = InAddress;
    Phone = InPhone;
}

std::string Publisher::ToString() const
{
    return "Publisher: " + Name() + "\n - Address: " + Address() + "\n - Phone: " + Phone() + "\n - " + Books().ToString();
}

std::ostream& Publisher::Output(std::ostream& OutStream) const
{
    OutStream<<"P "<<Name().size()<<" "<<Name()<<" "<<Address().size()<<" "<<Address()<<" "<<Phone().size()<<" "<<Phone()<<" "<<Books();
    return OutStream;
}

std::istream& Publisher::Input(std::istream& InStream)
{
    char ID;
    InStream>>ID;
    if(ID != 'P') throw InvalidPublisherException("Invalid data format");

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

void Publisher::Enter(std::istream& InStream, std::ostream& OutStream)
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