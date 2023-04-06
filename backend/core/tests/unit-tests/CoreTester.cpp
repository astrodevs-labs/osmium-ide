/*
** backend, 2022
** CoreTester.cpp by 0xMemoryGrinder
*/


#include <ranges>
#include <algorithm>
#include "CoreTester.hpp"

bool core::tests::CoreTester::hasHandler(core::handler_id id) const
{
    for (auto &[type, handlers]: _handlers) {
        for (auto &[priority, prioritizedHandlers]: handlers) {
            if (prioritizedHandlers.find(id) != prioritizedHandlers.end())
                return true;
        }
    }
    return false;
}

bool
core::tests::CoreTester::hasHandler(uint64_t priority, core::handler_id id) const
{
    for (auto &[type, handlers]: _handlers) {
        if (handlers.find(priority) != handlers.end()) {
            if (handlers.at(priority).find(id) != handlers.at(priority).end())
                return true;
        }
    };
    return false;
}

bool core::tests::CoreTester::hasHandler(uint64_t priority) const
{
    for (auto &[type, handlers]: _handlers) {
        if (handlers.find(priority) != handlers.end())
            return true;
    }
    return false;
}
