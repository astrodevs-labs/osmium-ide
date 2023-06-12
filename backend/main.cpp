#include <iostream>
#include <memory>
#include "Core.hpp"

int main()
{
    std::cout << "Hello, World!" << std::endl;

    std::shared_ptr<core::Core> core = std::make_shared<core::Core>();

    core->loadSoFile("./backend-frontCommunication.so");

    std::promise<void> prom;
    std::future<void> fut = prom.get_future();
    fut.wait();
}
