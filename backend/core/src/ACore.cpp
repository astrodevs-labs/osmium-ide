/*
** Project, 2022
** ACore.cpp by 0xMemoryGrinder
*/


#include "ACore.hpp"

core::ACore::ACore()
{

}

template<typename T>
void core::ACore::registerHandler(uint64_t priority, std::function<void(std::shared_ptr<T>)> handler)
{
    _handlers[std::type_index(typeid(T))][priority].push_back([handler](std::any anyMessage) {
        handler(std::any_cast<std::shared_ptr<T>>(anyMessage));
    });
}

template<typename T>
std::future<std::shared_ptr<T>> core::ACore::emitMessage(std::shared_ptr<T> message)
{
    return std::async(std::launch::async, [this, message]() {
        for (auto &priority : _handlers[std::type_index(typeid(T))]) {
            for (auto &handler : priority.second) {
                handler(message);
            }
        }
        return message;
    });
}