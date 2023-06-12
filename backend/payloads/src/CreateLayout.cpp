/*
** Project, 2023
** CreateLayout.cpp by LouisPiochaud
*/

#include "CreateLayout.hpp"

namespace payloads
{

    const std::string &CreateLayout::getName() const
    {
        return this->_name;
    }

    void CreateLayout::setName(std::string &name)
    {
        this->_name = name;
    }

    std::shared_ptr<Component> CreateLayout::getResponse() const
    {
        return this->_response;
    }

    void CreateLayout::setResponse(std::shared_ptr<Component> response)
    {
        this->_response = response;
    }

} // namespace payloads
