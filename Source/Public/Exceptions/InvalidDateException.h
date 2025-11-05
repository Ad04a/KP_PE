#pragma once

#include <stdexcept>
#include <string>

using namespace std;

class InvalidDateException : std::runtime_error
{

    private:
    //inline static const string DefaultMessage = "Invalid Date";

    public:

    InvalidDateException() : runtime_error("Invalid Date"){};
    InvalidDateException(string InMessage) : runtime_error("Invalid Date: " + InMessage){};
};