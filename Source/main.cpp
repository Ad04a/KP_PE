
#include "SystemUtils/System.h"

int main()
{
    SystemUtils::System ManaginSystem(&std::cin, &std::cout);
    ManaginSystem.Start();

    return 0;
}