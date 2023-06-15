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

    std::shared_ptr<Component> Component::createExpandableListView(uid uid, ExpendableList list) {
        auto component = std::make_shared<Component>(uid);
        component->type = "ExpandableList";
        component->addProp({ "name", list.getName(), true });
        component->addProp({ "type", list.getType(), true });
        for (auto item : list.getItems()) {
            component->addChild(createExpandableListView(uid + item.getName(), item));
        }
        return component;
    }

} // namespace payloads