//
// Created by trigr on 06/06/2023.
//

#include "../include/NewLayout.hpp"
#include <stdexcept>

payloads::NewLayout::NewLayout(std::string name, std::shared_ptr<Component> tree) {
    this->_name = std::move(name);
    this->_tree = std::move(tree);
}

std::string payloads::NewLayout::getName() {
    return this->_name;
}

std::shared_ptr<payloads::Component> payloads::NewLayout::getTree() {
    return this->_tree;
}

void payloads::NewLayout::setComponentFromParent(std::string parentId, std::shared_ptr<Component> toAdd) {
    auto parent = getComponent(std::move(parentId));

    if (parent != nullptr) {
        parent->addChild(std::move(toAdd));
    } else {
        throw std::runtime_error("Parent not fount to add component in layout");
    }
}

std::shared_ptr<payloads::Component> payloads::NewLayout::getComponent(std::string id) {
    if (this->_tree->id == id)
        return this->_tree;
    return this->_tree->findComponentById(id);
}

bool payloads::NewLayout::hasComponent(std::string id) {
    return (this->getComponent(std::move(id)) != nullptr);
}
