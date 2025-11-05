#pragma once

#include <stdexcept>
#include <string>

using namespace std;

class InvalidPhoneException : std::runtime_error
{
    public:

    InvalidPhoneException() : runtime_error("Invalid Phone"){};
    InvalidPhoneException(string InMessage) : runtime_error("Invalid Phone: " + InMessage){};
};