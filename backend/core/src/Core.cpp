/*
** Project, 2022
** Core.cpp by 0xMemoryGrinder
*/


#include "Core.hpp"
#include "utils/DynamicLoader.hpp"
#include "MessagingInterface.hpp"


void core::Core::loadSoFile(std::string filePath)
{
    DynamicLoader loader;

    loader.loadHandler(filePath);

    auto createModuleFct = loader.loadSymbol<void *(*)(std::shared_ptr<MessagingInterface>)>("createModule");
    auto getModuleNameFct = loader.loadSymbol<std::string(*)()>("getModuleName");
    auto moduleName = getModuleNameFct();
    auto shared = shared_from_this();
    auto msgInterface = std::make_shared<MessagingInterface>(shared, moduleName);
    auto module = reinterpret_cast<IModule *>(createModuleFct(msgInterface));

    this->_loadedLibraries.push_back(std::move(loader));
    this->_loadedModules.push_back(std::unique_ptr<IModule>(module));
}