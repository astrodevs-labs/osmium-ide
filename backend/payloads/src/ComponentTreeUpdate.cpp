#include <utility>

#include "ComponentTreeUpdate.hpp"

ComponentTreeUpdate::ComponentTreeUpdate(Action action, payloads::Component component) :
    _action(action),
    _component(std::move(component)) {
}

ComponentTreeUpdate::Action ComponentTreeUpdate::getAction() const {
    return _action;
}

const payloads::Component& ComponentTreeUpdate::getComponent() const {
    return _component;
}
