#include <iostream>
#include <memory>
#include "Core.hpp"

int main()
{
    std::cout << "Hello, World!" << std::endl;

    std::shared_ptr<core::ACore> core = std::make_shared<core::Core>();

    return 0;
}
