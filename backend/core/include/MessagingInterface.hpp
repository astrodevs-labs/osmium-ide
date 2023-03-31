/*
** backend, 2022
** MessagingInterface.hpp by 0xMemoryGrinder
*/

#pragma once

#include <memory>
#include <functional>
#include <future>
#include "Core.hpp"

namespace core
{

    /**
     * @brief MessagingInterface is the class passed to the modules to allow them to communicate with the core
     */
    class MessagingInterface
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            /**
             * @brief Construct a new Messaging Interface object
             * @param core The core instance to communicate with
             * @param moduleName The name of the module that will use this interface, used to identify the source of the message
             */
            MessagingInterface(std::shared_ptr<Core> core, std::string moduleName);

            ~MessagingInterface() = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:
            /**
             * @property _moduleName The name of the module that will be sent along with each emitted message
             */
            std::string _moduleName;
            /**
             * @property _core The core instance to register handlers and emit messages
             */
            std::shared_ptr<Core> _core;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            /**
             * @brief Register a handler for a specific message type, the handler will be called when a message of the same type is emitted
             * @tparam T The type of the message to handle
             * @param priority A priority to sort the handlers, the higher the priority, the later the handler will be called (0 is the highest priority). If two handlers have the same priority, the order is undefined. You should leave space between priorities to allow other modules to register handlers between yours.
             * @param handler The handler to register. The handler will be called with the message and the name of the module that emitted it.
             */
            template<typename T>
            void registerHandler(uint64_t priority, std::function<void(std::shared_ptr<T>, std::string)> handler)
            {
                _core->registerHandler<T>(priority, handler);
            }

            /**
             * @brief Emit a message to the core, the core will then forward it to all the modules that registered handlers for this message type
             * @tparam T The type of the message to emit
             * @param message The message to emit
             * @return A future that will be resolved when all the handlers have been called. The future will contain the message that was emitted and mutations if any were made by the handlers.
             */
            template<typename T>
            std::future<std::shared_ptr<T>> emitMessage(std::shared_ptr<T> message)
            {
                return _core->emitMessage<T>(message, _moduleName);
            }

        private:


//////////////////////--------------------------/////////////////////////

    };
}
