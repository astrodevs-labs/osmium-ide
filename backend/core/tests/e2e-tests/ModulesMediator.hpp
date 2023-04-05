/*
** backend, 2023
** ModulesMediator.hpp by 0xMemoryGrinder
*/

#pragma once

#include <string>
#include <map>
#include <vector>
#include <any>
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <memory>
#include <cstring>

namespace core::tests
{
    template<typename T>
    concept String = std::is_same_v<T, std::string>;

    template<typename T>
    concept POD = std::is_standard_layout_v<T> && std::is_trivial_v<T>;

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
            static inline key_t _key;
            static inline int _shmid;
            static inline uint8_t *_shm;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            static void setup()
            {
                ModulesMediator::_key = ftok("shmfile", 65);
                ModulesMediator::_shmid = shmget(ModulesMediator::_key, 1024, 0666|IPC_CREAT);
                ModulesMediator::_shm = (uint8_t *)shmat(ModulesMediator::_shmid, nullptr, 0);
            }

            static void writerTeardown()
            {
                shmdt(ModulesMediator::_shm);
            }

            static void readerTeardown()
            {
                shmdt(ModulesMediator::_shm);
                shmctl(ModulesMediator::_shmid, IPC_RMID, nullptr);
                ModulesMediator::_received.clear();
                ModulesMediator::_sent.clear();
            }

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

            template<String T>
            static void addReceived(std::string moduleName, std::shared_ptr<T> data)
            {
                std::cerr << moduleName << " received: " << data << std::endl;
                std::memcpy(ModulesMediator::_shm, moduleName.c_str(), moduleName.size());
                _shm[moduleName.size()] = 0;
                std::memcpy(ModulesMediator::_shm + moduleName.size() + 1, data->c_str(), data->size());
            }

            template<POD T>
            static void addReceived(std::string moduleName, std::shared_ptr<T> data)
            {
                std::cerr << moduleName << " received: " << data << std::endl;
                std::memcpy(ModulesMediator::_shm, moduleName.c_str(), moduleName.size());
                _shm[moduleName.size()] = 0;
                std::memcpy(ModulesMediator::_shm + moduleName.size() + 1, data.get(), sizeof(T));
            }

            static void parseReceived()
            {
                std::string moduleName = (char *)ModulesMediator::_shm;
                std::cerr << "moduleName: " << moduleName << std::endl;
                switch (ModulesMediator::_type)
                {
                    case Type::STRING:
                    {
                        std::string data = (char *)(ModulesMediator::_shm + moduleName.size() + 1);
                        std::cerr << "data: " << data << std::endl;
                        ModulesMediator::_received[moduleName].emplace_back(data);
                        break;
                    }
                    case Type::INT:
                    {
                        int data = *(int *)(ModulesMediator::_shm + moduleName.size() + 1);
                        std::cerr << "data: " << data << std::endl;
                        ModulesMediator::_received[moduleName].emplace_back(data);
                        break;
                    }
                    case Type::FLOAT:
                    {
                        float data = *(float *)(ModulesMediator::_shm + moduleName.size() + 1);
                        std::cerr << "data: " << data << std::endl;
                        ModulesMediator::_received[moduleName].emplace_back(data);
                        break;
                    }
                    case Type::DOUBLE:
                    {
                        double data = *(double *)(ModulesMediator::_shm + moduleName.size() + 1);
                        std::cerr << "data: " << data << std::endl;
                        ModulesMediator::_received[moduleName].emplace_back(data);
                        break;
                    }
                    case Type::BOOL:
                    {
                        bool data = *(bool *)(ModulesMediator::_shm + moduleName.size() + 1);
                        std::cerr << "data: " << data << std::endl;
                        ModulesMediator::_received[moduleName].emplace_back(data);
                        break;
                    }
                    case Type::CHAR:
                    {
                        char data = *(char *)(ModulesMediator::_shm + moduleName.size() + 1);
                        std::cerr << "data: " << data << std::endl;
                        ModulesMediator::_received[moduleName].emplace_back(data);
                        break;
                    }
                    case Type::EMPTY:
                    {
                        ModulesMediator::_received[moduleName].emplace_back(nullptr);
                        break;
                    }
                    case Type::CUSTOM:
                    {
                        ModulesMediator::_received[moduleName].emplace_back(nullptr);
                        break;
                    }
                    default:
                        break;
                }
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
