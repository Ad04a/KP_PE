#pragma once

#include <stdexcept>
#include <string>

namespace Exceptions
{
    class FileException : public std::runtime_error
    {
        public:

        FileException() : runtime_error("File Error"){};
        FileException(std::string InMessage) : runtime_error("File Error: " + InMessage){};
    };
}