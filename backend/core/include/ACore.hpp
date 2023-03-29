/*
** Project, 2022
** ACore.hpp by 0xMemoryGrinder
*/

#pragma once

#include <iostream>
#include <memory>
#include <functional>
#include <any>
#include <regex>
#include <future>
#include <typeindex>
#include <vector>
#include <map>
#include "utils/DynamicLoader.hpp"
#include "IModule.hpp"

namespace core
{

    class ACore
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            ACore();

            virtual ~ACore() {};


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:

        protected:
            std::unordered_map<std::type_index, std::map<uint64_t, std::vector<std::function<void(std::any)>>>> _handlers;
            std::vector<DynamicLoader> _loadedLibraries;
            std::vector<std::unique_ptr<IModule>> _loadedModules;
        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            template<typename T>
            void registerHandler(uint64_t priority, std::function<void(std::shared_ptr<T>)> handler);

            template<typename T>
            std::future<std::shared_ptr<T>> emitMessage(std::shared_ptr<T> message);

        private:


//////////////////////--------------------------/////////////////////////

    };

} // core
