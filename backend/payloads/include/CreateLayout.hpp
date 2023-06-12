#pragma once

#include "Component.hpp"

namespace payloads
{

/**
 * @class CreateLayout
 * @brief The payload that will be emitted by the UI module to Layout module to generate the new root of the component tree. 
 * Since the request/response pattern will be used to retrieve the layout, a field in the payload is mandatory to store the response.


 */
    class CreateLayout
    {


////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            CreateLayout() = default;
            ~CreateLayout() = default;

//////////////////////--------------------------/////////////////////////


///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            
        protected:
        
        private:
            std::string _name;
            std::shared_ptr<Component> _response;

//////////////////////--------------------------/////////////////////////


///////////////////////////////// METHODS ///////////////////////////////
        public:
            const std::string &getName() const;
            void setName(std::string &name);
            std::shared_ptr<Component> getResponse() const;
            void setResponse(std::shared_ptr<Component> response);


        
        private:

//////////////////////--------------------------/////////////////////////

    };

} // namespace payloads