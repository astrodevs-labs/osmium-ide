/*
** Project, 2022
** Core.hpp by 0xMemoryGrinder
*/

#pragma once

#include "ACore.hpp"

namespace core
{

    class Core : public ACore, public std::enable_shared_from_this<Core>
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            Core();
            ~Core() override;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void loadSoFile(std::string filePath);

        private:


//////////////////////--------------------------/////////////////////////

    };

} // core
