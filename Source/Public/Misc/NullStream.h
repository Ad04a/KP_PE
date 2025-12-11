#pragma once

#include <iostream>

#include <streambuf>
#include <ostream>

namespace NullStream
{
    struct NullBuffer : std::streambuf {
    int overflow(int c) override {
        return c;   // accept and ignore character
    }
    };

    struct NullStream : std::ostream {
        NullStream() : std::ostream(&buf) {}
    private:
        NullBuffer buf;
    };

    inline NullStream NullOut = NullStream();
}


