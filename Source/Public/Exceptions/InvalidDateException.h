#pragma once

#include <stdexcept>
#include <string>

using namespace std;

class InvalidDateException : std::runtime_error
{
    public:

    InvalidDateException() : runtime_error("Invalid Date"){};
    InvalidDateException(string InMessage) : runtime_error("Invalid Date: " + InMessage){};
};