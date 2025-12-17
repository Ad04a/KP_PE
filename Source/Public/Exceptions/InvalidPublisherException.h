#pragma once

#include <stdexcept>
#include <string>

namespace Exceptions
{   
    class InvalidPublisherException : public std::runtime_error
    {
        public:

        InvalidPublisherException() : runtime_error("Invalid Publisher"){};
        InvalidPublisherException(std::string InMessage) : runtime_error("Invalid Publisher: " + InMessage){};
    };
}