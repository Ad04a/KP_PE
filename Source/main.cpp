
#include "Publisher.h"

//#include "Property.h"
#include "SystemUtils/System.h"
//#include "SystemUtils/SystemHandlers.h"

#include <iostream>
//#include <vector>
//#include <string>

//#include "UI/Menu.h"
//#include "Misc/Delegate.h"

int main()
{
    SystemUtils::System ManaginSystem(&std::cin, &std::cout);
    ManaginSystem.Start();

    return 0;
}