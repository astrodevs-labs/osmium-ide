//
// Created by trigr on 06/06/2023.
//

#ifndef BACKEND_NEWLAYOUT_HPP
#define BACKEND_NEWLAYOUT_HPP

#include <string>
#include <vector>
#include <memory>
#include "Component.hpp"

namespace payloads {
    class NewLayout
    {
        public:
            NewLayout(std::string name, std::shared_ptr<Component> tree);
            ~NewLayout() = default;

        private:
            std::string _name;
            std::shared_ptr<Component> _tree;

        public:
            std::string getName();
            std::shared_ptr<Component> getTree();
            void setComponentFromParent(std::string parentId, std::shared_ptr<Component> toAdd);
            std::shared_ptr<Component> getComponent(std::string id);
            bool hasComponent(std::string id);

    };
}

#endif // BACKEND_NEWLAYOUT_HPP
