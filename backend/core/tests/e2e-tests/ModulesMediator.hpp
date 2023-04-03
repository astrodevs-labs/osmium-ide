/*
** backend, 2023
** ModulesMediator.hpp by 0xMemoryGrinder
*/

#pragma once

#include <string>
#include <map>
#include <vector>
#include <any>

namespace core::tests
{

    class ModulesMediator
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            ModulesMediator() = default;

            ~ModulesMediator() = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            enum Type
            {
                STRING,
                INT,
                FLOAT,
                DOUBLE,
                BOOL,
                CHAR,
                EMPTY,
                CUSTOM
            };

        private:
            static inline std::string name;
            static inline Type _type;
            static inline std::map<std::string, std::vector<std::any>> _received;
            static inline std::map<std::string, std::vector<std::any>> _sent;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            static void setType(Type type)
            {
                ModulesMediator::_type = type;
            }

            static Type getType()
            {
                return ModulesMediator::_type;
            }

            template<typename T>
            static void addSend(std::string moduleName, T data)
            {
                ModulesMediator::_sent[moduleName].push_back(data);
            }

            template<typename T>
            static void addReceived(std::string moduleName, T data)
            {
                ModulesMediator::_received[moduleName].push_back(data);
            }

            static std::vector<std::any> getReceived(std::string moduleName)
            {
                return ModulesMediator::_received[moduleName];
            }

            static std::vector<std::any> getSent(std::string moduleName)
            {
                return ModulesMediator::_sent[moduleName];
            }


        private:


//////////////////////--------------------------/////////////////////////

    };
}
