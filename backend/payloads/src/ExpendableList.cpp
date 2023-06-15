#include "./ExpendableList.hpp"

#include <utility>

ExpendableList::ExpendableList(std::string name, std::string type, std::vector<ExpendableList> items)
{
    this->items = std::move(items);
    this->name = std::move(name);
    this->type = std::move(type);
}

const std::vector<ExpendableList> &ExpendableList::getItems() const
{
    return this->items;
}

std::string ExpendableList::getName() const
{
    return this->name;
}

std::string ExpendableList::getType() const
{
    return this->type;
}
