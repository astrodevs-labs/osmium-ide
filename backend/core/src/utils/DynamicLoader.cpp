/*
** Project, 2022
** DynamicLoader.cpp by 0xMemoryGrinder
*/

#include <dlfcn.h>
#include "utils/DynamicLoader.hpp"
#include "exceptions/DynamicLibraryLoadingException.hpp"

core::DynamicLoader::DynamicLoader(std::string filepath)
{
    _handle = dlopen(filepath.c_str(), RTLD_LAZY);

    if (!this->_handle) {
        std::cerr << "Error : " << dlerror() << std::endl;
        throw DynamicLibraryLoadingException("Error while loading library");
    }
}

core::DynamicLoader::~DynamicLoader()
{
    dlclose(this->_handle);
}
