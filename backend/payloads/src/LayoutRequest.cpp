/*
** payload-library, 2022
** LayoutRequest.cpp by 0xMemoryGrinder
*/


#include "LayoutRequest.hpp"

std::shared_ptr<payloads::Component> payloads::LayoutRequest::getTree() const
{
    return _tree;
}

void payloads::LayoutRequest::setTree(std::shared_ptr<Component> tree)
{
    _tree = tree;
}
