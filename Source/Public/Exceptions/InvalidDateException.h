#pragma once

#include <stdexcept>
#include <string>

namespace Exceptions
{
    class InvalidDateException : public std::runtime_error
    {
        public:

        InvalidDateException() : runtime_error("Invalid Date"){};
        InvalidDateException(std::string InMessage) : runtime_error("Invalid Date: " + InMessage){};
    };
}