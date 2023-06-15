#pragma once

#include "../../core/include/MessagingInterface.hpp"

namespace hierarchy
{
    class HierarchyModule
    {

        ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

    public:
        HierarchyModule(std::shared_ptr<core::MessagingInterface> msg);

        ~HierarchyModule() = default;

        //////////////////////--------------------------/////////////////////////

        ///////////////////////////// PROPERTIES ////////////////////////////////
    public:
    private:
        std::shared_ptr<core::MessagingInterface> _msg;

        //////////////////////--------------------------/////////////////////////

        /////////////////////////////// METHODS /////////////////////////////////
    public:
    private:
        //////////////////////--------------------------/////////////////////////
    };
} // namespace hierarchy
