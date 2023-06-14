/*
** Project, 2023
** Component.cpp by LouisPiochaud
*/

#include "Component.hpp"
#include "../../core/include/Core.hpp"

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

    std::shared_ptr<Component> Component::createLeftSideBarComponent(std::vector<std::shared_ptr<Component>> children)
    {
        std::string id = core::Core::generateHandlerId();
        std::shared_ptr<Component> component = std::make_shared<Component>(id);
        component->type = "left-side-bar";
        for (auto child: children) {
            component->addChild(std::move(child));
        }
        return component;
    }

} // namespace payloads