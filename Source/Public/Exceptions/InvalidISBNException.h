#pragma once

#include <stdexcept>
#include <string>

using namespace std;

class InvalidISBNException : std::runtime_error
{
    public:

    InvalidISBNException() : runtime_error("Invalid ISBN"){};
    InvalidISBNException(string InMessage) : runtime_error("Invalid ISBN: " + InMessage){};
};