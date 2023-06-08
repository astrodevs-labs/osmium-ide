/*
** Project, 2023
** CreateLayout.cpp by LouisPiochaud
*/

#include "CreateLayout.hpp"

namespace payloads
{

    std::shared_ptr<Component> CreateLayout::getResponse() const
    {
        return this->_response;
    }

    void CreateLayout::setResponse(std::shared_ptr<Component> response)
    {
        this->_response = response;
    }

} // namespace payloads
