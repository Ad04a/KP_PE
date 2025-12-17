#pragma once

#include <stdexcept>
#include <string>

namespace Exceptions
{
    class InvalidBookException : public std::runtime_error
    {
        public:

        InvalidBookException() : runtime_error("Invalid Book"){};
        InvalidBookException(std::string InMessage) : runtime_error("Invalid Book: " + InMessage){};
    };
}