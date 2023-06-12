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

    struct Property {
        std::string name;
        std::string value;
        bool toTransmit;
    };

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
            std::vector<std::shared_ptr<Component>> children;
            std::vector<Property> props;
            
        private:

//////////////////////--------------------------/////////////////////////


///////////////////////////////// METHODS ///////////////////////////////

        public:
            void addChild(std::shared_ptr<Component> child);
            void removeChild(uid id);
            void addProp(Property prop);
            void removeProp(std::string key);
            static std::shared_ptr<Component> createSimpleIconComponent(std::string icon);

        private:

//////////////////////--------------------------/////////////////////////

    };

} // namespace payloads