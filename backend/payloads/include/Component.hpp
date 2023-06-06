/*
** Project, 2023
** Component.hpp by LouisPiochaud
*/

#pragma once

#include <string>
#include <vector>
#include <memory>

using uid = std::string;

namespace payloads
{

    /**
     * @class Component
     * @brief This type will be used inside payload and it thus needs to fit 
     * all components the frontend can handle.
     */
    class Component
    {


////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            Component(uid id);
            Component(uid id, std::shared_ptr<Component> parent);
            ~Component() = default;

//////////////////////--------------------------/////////////////////////


///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            uid id;
            std::string type;
            std::shared_ptr<Component> parent;
            std::vector<Component> children;
            std::vector <std::pair<std::string, std::string>> props;
            
        private:

//////////////////////--------------------------/////////////////////////


///////////////////////////////// METHODS ///////////////////////////////

        public:
            void addChild(Component child);
            void removeChild(uid id);
            void addProp(std::pair<std::string, std::string> prop);
            void removeProp(std::string key);
            
        private:

//////////////////////--------------------------/////////////////////////

    };

} // namespace payloads