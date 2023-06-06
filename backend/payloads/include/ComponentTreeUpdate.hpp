#pragma once

#include <string>
#include <vector>
#include <map>

class ComponentTreeUpdate {

    enum class Action {
        ADD,
        REMOVE,
        UPDATE
    };

     public:
        ComponentTreeUpdate(Action action, std::string type, std::string uid, std::vector<std::map<std::string, std::string>> _prop, std::vector<ComponentTreeUpdate> children);
        ~ComponentTreeUpdate() = default;

    private:
        Action _action;
        std::string _type;
        std::string _uid;
        std::vector<std::map<std::string, std::string>> _props;
        std::vector<ComponentTreeUpdate> children;

    public:
        Action getAction() const;
        const std::string &getType() const;
        const std::string &getUid() const;
        const std::vector<std::map<std::string, std::string>> &getProps() const;
        const std::vector<ComponentTreeUpdate> &getChildren() const;
};
