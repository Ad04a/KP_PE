#pragma once

#include "Misc/NullStream.h"

namespace DataUtils
{
    class IInputable
    {
        virtual std::istream& Input(std::istream& InStream, std::ostream& FeedbackStream = NullStream::NullOut) = 0;
    };
}
