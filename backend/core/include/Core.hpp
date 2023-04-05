/*
** Project, 2022
** ACore.hpp by 0xMemoryGrinder
*/

#pragma once

#include <iostream>
#include <memory>
#include <functional>
#include <map>
#include <any>
#include <future>
#include <typeindex>
#include <utility>
#include <vector>
#include "utils/DynamicLoader.hpp"
#include "IModule.hpp"

namespace core
{

    /**
     * @class Core
     * @brief Core class of the backend that will load the modules and handle the communication between them
     */
    class Core : public std::enable_shared_from_this<Core>
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            Core() = default;

            ~Core() = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:

        protected:
            /**
             * @property _handlers map of handlers for each message type sorted by their priority
             */
            std::unordered_map<std::type_index, std::map<uint64_t, std::map<uint64_t, std::function<void(std::any, std::string)>>>> _handlers;
            /**
             * @property _loadedLibraries vector of DynamicLoader instances for each loaded library
             */
            std::vector<DynamicLoader> _loadedLibraries;
            /**
             * @property _loadedModules vector of each loaded module
             */
            std::vector<std::unique_ptr<IModule>> _loadedModules;
        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            /**
             * @brief Register a handler for a specific message type with a given priority
             * @tparam T The type of the message to handle
             * @param priority A priority to sort the handlers, the higher the priority, the later the handler will be called (0 is the highest priority). If two handlers have the same priority, the order is undefined. You should leave space between priorities to allow other modules to register handlers between yours.
             * @param handler The handler to register. The handler will be called with the message and the name of the module that emitted it.
             * @return The ID of the registered handler
             */
            template<typename T>
            uint64_t registerHandler(uint64_t priority, std::function<void(std::shared_ptr<T>, std::string)> handler)
            {
                //TODO: Change id generation

                static uint64_t handlerId = 0;
                const uint64_t id = ++handlerId;

                _handlers[std::type_index(typeid(T))][priority][id] = [handler](std::any anyMessage, std::string moduleName) {
                    handler(std::any_cast<std::shared_ptr<T>>(anyMessage), moduleName);
                };
                return id;
            }

            /**
             * @brief Remove the handler identified by its id from _handlers.
             * @param id The id of the handler to remove.
             */
            void removeHandler(uint64_t id)
            {
                for (auto &typeIndex: _handlers) {
                    for (auto &priority : _handlers[typeIndex.first]) {
                        for (auto &handlerId : priority.second) {
                            if (handlerId.first == id) {
                                priority.second[id] = nullptr;
                                return;
                            }
                        }
                    }
                }
            }

            /**
             * @brief Emit a message then forward it to all the modules that registered handlers for this message type
             * @tparam T The type of the message to emit
             * @param message The message to emit
             * @param moduleName The name of the module which emitted the message
             * @return A future that will be resolved when all the handlers have been called. The future will contain the message that was emitted and mutations if any were made by the handlers.
             */
            template<typename T>
            std::future<std::shared_ptr<T>> emitMessage(std::shared_ptr<T> message, std::string moduleName)
            {
                return std::async(std::launch::async, [this, message, moduleName]() {
                    for (auto &priority : _handlers[std::type_index(typeid(T))]) {
                        for (auto &handlerId : priority.second) {
                            handlerId.second(message, moduleName);
                        }
                    }
                    return message;
                });
            }

            /**
             * @brief Load a dynamic library, extract its module name and call the createModule symbol with a specialized version of MessagingInterface instance
             * @param filePath The path of the dynamic library to load
             */
            void loadSoFile(std::string filePath);

        private:


//////////////////////--------------------------/////////////////////////

    };

} // core
