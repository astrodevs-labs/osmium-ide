/*
** backend, 2023
** CoreTester.hpp by 0xMemoryGrinder
*/

#pragma once

#include "Core.hpp"

namespace core
{
    namespace tests
    {

        class CoreTester: public Core
        {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

            public:


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
            public:


            private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
            public:
                template<typename T>
                bool hasHandler(handler_id id) const
                {
                    const auto typeIdx = std::type_index(typeid(T));
                    if (_handlers.find(typeIdx) == _handlers.end())
                        return false;
                    for (auto &[priority, prioritizedHandlers]: _handlers.at(typeIdx)) {
                        if (prioritizedHandlers.find(id) != prioritizedHandlers.end())
                            return true;
                    }
                    return false;
                }

                template<typename T>
                bool hasHandler(uint64_t priority, handler_id id) const
                {
                    const auto typeIdx = std::type_index(typeid(T));
                    if (_handlers.find(typeIdx) == _handlers.end())
                        return false;
                    if (_handlers.at(typeIdx).find(priority) != _handlers.at(typeIdx).end()) {
                        if (_handlers.at(typeIdx).at(priority).find(id) != _handlers.at(typeIdx).at(priority).end())
                            return true;
                    }
                    return false;
                }

                template<typename T>
                bool hasHandler(uint64_t priority) const
                {
                    const auto typeIdx = std::type_index(typeid(T));
                    if (_handlers.find(typeIdx) == _handlers.end())
                        return false;
                    if (_handlers.at(typeIdx).find(priority) != _handlers.at(typeIdx).end())
                        return true;
                    return false;
                }

                bool hasHandler(handler_id id) const;

                bool hasHandler(uint64_t priority, handler_id id) const;

                bool hasHandler(uint64_t priority) const;


            private:


//////////////////////--------------------------/////////////////////////

        };

    } // core
} // tests
