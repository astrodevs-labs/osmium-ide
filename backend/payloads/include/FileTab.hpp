/*
** payload-library, 2023
** FileTab.hpp by Leon
*/

#pragma once

#include <memory>
#include "Component.hpp"

namespace payloads
{

    class FileTab
    {

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            FileTab() = default;

            ~FileTab() = default;

            //////////////////////--------------------------/////////////////////////

            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
        private:
            std::string _content;
            std::string _encodedContent;
            std::string _filename;
            std::string _path;

            //////////////////////--------------------------/////////////////////////

            /////////////////////////////// METHODS /////////////////////////////////
        public:
            std::string getContent();
            std::string getEncodedContent();
            std::string getFilename();
            std::string getpath();

            void setContent(std::string);
            void setEncodedContent(std::string);
            void setFilename(std::string);
            void setpath(std::string);

        private:
            //////////////////////--------------------------/////////////////////////
    };
} // namespace payloads
