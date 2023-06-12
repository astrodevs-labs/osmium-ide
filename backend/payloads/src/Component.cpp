/*
** Project, 2023
** Component.cpp by LouisPiochaud
*/

#include "Component.hpp"

namespace payloads
{

    Component::Component(uid id) : id(id) {}

    Component::Component(uid id, std::shared_ptr<Component> parent) : id(id), parent(parent) {}

    Component::Component(Property content, Property encodedContent, Property filename, Property path)
    {
        this->addProp(content);
        this->addProp(encodedContent);
        this->addProp(filename);
        this->addProp(path);
    }

    void Component::addChild(std::shared_ptr<Component> child) { this->children.push_back(child); }

    void Component::removeChild(uid id)
    {
        for (auto it = this->children.begin(); it != this->children.end(); it++) {
            if ((*it)->id == id) {
                this->children.erase(it);
                return;
            }
        }
    }

    void Component::addProp(Property prop) { this->props.push_back(prop); }

    void Component::removeProp(std::string key)
    {
        for (auto it = this->props.begin(); it != this->props.end(); it++) {
            if (it->name == key) {
                this->props.erase(it); // not fast
                return;
            }
        }
    }

} // namespace payloads
