/*
** payload-library, 2023
** LayoutRequest.hpp by 0xMemoryGrinder
*/

#pragma once


#include <memory>
#include "Component.hpp"

namespace payloads
{

    class LayoutRequest
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            LayoutRequest() = default;

            ~LayoutRequest() = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:
            std::shared_ptr<Component> _tree;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            std::shared_ptr<Component> getTree() const;

            void setTree(std::shared_ptr<Component> tree);

        private:


//////////////////////--------------------------/////////////////////////

    };
}