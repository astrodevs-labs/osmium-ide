#include <utility>

#include "ComponentTreeUpdate.hpp"

ComponentTreeUpdate::ComponentTreeUpdate(Action action, const std::shared_ptr<payloads::Component> &component) {
    _action = std::move(action);
    _component = component;
}

ComponentTreeUpdate::Action ComponentTreeUpdate::getAction() const {
    return _action;
}

const std::shared_ptr<payloads::Component>& ComponentTreeUpdate::getComponent() const {
    return _component;
}
