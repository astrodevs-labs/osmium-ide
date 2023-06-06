//
// Created by trigr on 06/06/2023.
//

#include <utility>

#include "../include/ComponentStateEvent.hpp"

ComponentStateEvent::ComponentStateEvent(std::string id, std::string event, std::map<std::string, std::string> data) {
    this->_data = std::move(data);
    this->_id = std::move(id);
    this->_event = std::move(event);
}

std::string ComponentStateEvent::getId() {
    return this->_id;
}

std::string ComponentStateEvent::getEvent() {
    return this->_event;
}

std::string ComponentStateEvent::getDataValue(const std::string& key) {
    if (this->_data.contains(key))
        return this->_data[key];
    return nullptr;
}

std::map<std::string, std::string> ComponentStateEvent::getData() {
    return this->_data;
}
