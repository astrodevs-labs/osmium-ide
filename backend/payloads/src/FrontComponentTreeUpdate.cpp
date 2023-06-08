#include <utility>

#include "FrontComponentTreeUpdate.hpp"

FrontComponentTreeUpdate::FrontComponentTreeUpdate(Action action, const std::shared_ptr<payloads::Component> &component) {
    _action = std::move(action);
    _component = component;
}

FrontComponentTreeUpdate::Action FrontComponentTreeUpdate::getAction() const {
    return _action;
}

const std::shared_ptr<payloads::Component>& FrontComponentTreeUpdate::getComponent() const {
    return _component;
}
