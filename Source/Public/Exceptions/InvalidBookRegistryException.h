#pragma once

#include <stdexcept>
#include <string>

namespace Exceptions
{
    class InvalidBookRegistryException : public std::runtime_error
    {
        public:

        InvalidBookRegistryException() : runtime_error("Invalid BookRegistry"){};
        InvalidBookRegistryException(std::string InMessage) : runtime_error("Invalid BookRegistry: " + InMessage){};
    };
}