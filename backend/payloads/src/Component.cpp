/*
** Project, 2023
** Component.cpp by LouisPiochaud
*/

#include "Component.hpp"

namespace payloads
{

    Component::Component(uid id) : id(id) {}

    Component::Component(uid id, std::shared_ptr<Component> parent) : id(id), parent(parent) {}

    std::shared_ptr<Component> Component::CreatFileTab(std::string id, std::string content, std::string encodedContent, std::string filename,
                                                       std::string path)
    {
        auto tab = std::make_shared<Component>(id);

        this->addProp({"content", content, true});
        this->addProp({"encodedContent", encodedContent, true});
        this->addProp({"filename", filename, true});
        this->addProp({"path", path, true});
        return tab;
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
