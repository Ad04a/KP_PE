#include "Publisher.h"

Publisher::Publisher(std::string InName, std::string InAddress, std::string InPhone)
{
    Name = InName;
    Address = InAddress;
    Phone = InPhone;
}

std::string Publisher::ToString() const
{
    return "";
}

std::ostream& Publisher::Output(std::ostream& OutStream) const
{
    return OutStream;
}

std::istream& Publisher::Input(std::istream& InStream)
{
    return InStream;
}

void Publisher::Enter(std::istream& InStream, std::ostream& OutStream)
{

}