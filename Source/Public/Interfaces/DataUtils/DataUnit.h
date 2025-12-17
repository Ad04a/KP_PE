#pragma once

#include "Interfaces/DataUtils/Outputable.h"
#include "Interfaces/DataUtils/Stringifiable.h"
#include "Interfaces/DataUtils/Inputable.h"
#include "Interfaces/DataUtils/Enterable.h"

namespace Data
{
    namespace Utils
    {
        class DataUnit : public IOutputable, public IStringifiable, public IInputable, public IEnterable
        {
        };
    }
}