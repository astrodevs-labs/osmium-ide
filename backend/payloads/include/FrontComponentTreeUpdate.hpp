#pragma once

#include <memory>

#include "Component.hpp"

class FrontComponentTreeUpdate {

    enum Action {
        ADD,
        REMOVE,
        UPDATE
    };

     public:
        ComponentTreeUpdate(Action action, std::shared_ptr<payloads::Component> component);
        ~ComponentTreeUpdate() = default;

    private:
        Action _action;
        std::shared_ptr<payloads::Component> _component;

    public:
        Action getAction() const;
        const std::shared_ptr<payloads::Component>&getComponent() const;
};
