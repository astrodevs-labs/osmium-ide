/*
** Project, 2022
** Core.cpp by 0xMemoryGrinder
*/


#include "Core.hpp"
#include "utils/DynamicLoader.hpp"

void core::Core::loadSoFile(std::string filePath)
{
    DynamicLoader loader;

    loader.loadHandler(filePath);

    auto createModuleFct = loader.loadSymbol<void *(*)(std::shared_ptr<ACore>)>("createModule");
    auto shared = shared_from_this();
    auto module = reinterpret_cast<IModule *>(createModuleFct(shared));

    this->_loadedLibraries.push_back(std::move(loader));
    this->_loadedModules.push_back(std::unique_ptr<IModule>(module));
}

core::Core::Core()
{

}

core::Core::~Core()
{

}