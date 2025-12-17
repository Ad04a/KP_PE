#pragma once

#include <stdexcept>
#include <string>

namespace Exceptions
{
    class InvalidBookEntryException : public std::runtime_error
    {
        public:

        InvalidBookEntryException() : runtime_error("Invalid BookEntry"){};
        InvalidBookEntryException(std::string InMessage) : runtime_error("Invalid BookEntry: " + InMessage){};
    };
}