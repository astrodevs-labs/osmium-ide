#pragma once

#include <string>
#include <vector>

class ExpendableList {
    public:
        ExpendableList(std::string name, std::string type, std::vector<ExpendableList> items);
        ~ExpendableList() = default;

    private:
        std::vector<ExpendableList> items;
        std::string name;
        std::string type;

    public:
        const std::vector<ExpendableList> &getItems() const;
        std::string getName() const;
        std::string getType() const;
};
