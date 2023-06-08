#pragma once

#include <string>
#include <vector>
#include <map>

#include "Component.hpp"

class ComponentTreeUpdate {

    enum class Action {
        ADD,
        REMOVE,
        UPDATE
    };

     public:
        ComponentTreeUpdate(Action action, payloads::Component);
        ~ComponentTreeUpdate() = default;

    private:
        Action _action;
        payloads::Component _component;

    public:
        Action getAction() const;
        const payloads::Component& getComponent() const;
};
