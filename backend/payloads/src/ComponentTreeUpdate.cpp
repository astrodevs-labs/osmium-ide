#include <utility>

#include "ComponentTreeUpdate.hpp"

ComponentTreeUpdate::ComponentTreeUpdate(Action action, std::string type, std::string uid, std::vector<std::map<std::string, std::string>> _prop,
                                         std::vector<ComponentTreeUpdate> children)
{
    this->_action = action;
    this->_type = std::move(type);
    this->_uid = std::move(uid);
    this->_props = std::move(_prop);
    this->children = std::move(children);
}

ComponentTreeUpdate::Action ComponentTreeUpdate::getAction() const
{
    return this->_action;
}

const std::string &ComponentTreeUpdate::getType() const
{
    return this->_type;
}

const std::string &ComponentTreeUpdate::getUid() const
{
    return this->_uid;
}

const std::vector<std::map<std::string, std::string>> &ComponentTreeUpdate::getProps() const
{
    return this->_props;
}

const std::vector<ComponentTreeUpdate> &ComponentTreeUpdate::getChildren() const
{
    return this->children;
}
