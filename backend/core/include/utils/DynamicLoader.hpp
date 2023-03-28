/*
** Project, 2022
** DynamicLoader.hpp by 0xMemoryGrinder
*/

#pragma once

#include <dlfcn.h>
#include <iostream>

namespace core
{

    class DynamicLoader
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            DynamicLoader(std::string filepath);

            ~DynamicLoader();


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:
            void *_handle;

//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            template<typename T>
            T getFunction(std::string functionName)
            {
                void *func = dlsym(this->_handle, functionName.c_str());
                if (!func) {
                    std::cerr << "Error: " << dlerror() << std::endl;
                    return nullptr;
                }
                return reinterpret_cast<T>(func);
            }

        private:


//////////////////////--------------------------/////////////////////////

    };

} // core
