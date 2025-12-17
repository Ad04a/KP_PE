#pragma once

#include <stdexcept>
#include <string>

namespace Exceptions
{
    class InvalidISBNException : public std::runtime_error
    {
        public:

        InvalidISBNException() : runtime_error("Invalid ISBN"){};
        InvalidISBNException(std::string InMessage) : runtime_error("Invalid ISBN: " + InMessage){};
    };
}