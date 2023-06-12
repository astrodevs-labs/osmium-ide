/*
** Project, 2023
** Component.cpp by LouisPiochaud
*/

#include "Component.hpp"

namespace payloads
{

    Component::Component(uid id) : id(id)
    {
    }

    Component::Component(uid id, std::shared_ptr<Component> parent) : id(id), parent(parent)
    {
    }

    void Component::addChild(std::shared_ptr<Component> child)
    {
        this->children.push_back(child);
    }

    void Component::removeChild(uid id)
    {
        for (auto it = this->children.begin(); it != this->children.end(); it++)
        {
            if ((*it)->id == id)
            {
                this->children.erase(it);
                return;
            }
        }
    }

    void Component::addProp(Property prop)
    {
        this->props.push_back(prop);
    }

    std::shared_ptr<Component> Component::createTabComponent(std::string id, std::string name, std::string tabType)
    {
        auto tab = std::make_shared<Component>(id);

        tab->props.emplace_back("name", name, true);
        tab->props.emplace_back("tab-type", tabType, true);
        return tab;
    }

    void Component::removeProp(std::string key)
    {
        for (auto it = this->props.begin(); it != this->props.end(); it++)
        {
            if (it->name == key)
            {
                this->props.erase(it); // not fast
                return;
            }
        }
    }

    std::shared_ptr<Component> Component::findComponentById(std::string id) {
        for (auto child: this->children) {
            if (child->id == id)
                return child;
            auto component = child->findComponentById(id);
            if (component != nullptr)
                return component;
        }
        return nullptr;
    }

} // namespace payloads