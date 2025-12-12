#pragma once

#include <stdexcept>
#include <string>

class InvalidPhoneException : public std::runtime_error
{
    public:

    InvalidPhoneException() : runtime_error("Invalid Phone"){};
    InvalidPhoneException(std::string InMessage) : runtime_error("Invalid Phone: " + InMessage){};
};