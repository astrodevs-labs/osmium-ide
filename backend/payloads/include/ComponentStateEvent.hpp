//
// Created by trigr on 06/06/2023.
//

#ifndef BACKEND_COMPONENTSTATEEVENT_HPP
#define BACKEND_COMPONENTSTATEEVENT_HPP

#include <string>
#include <map>

class ComponentStateEvent
{
    public:
        ComponentStateEvent(std::string id, std::string event, std::map<std::string, std::string> data);
        ~ComponentStateEvent() = default;

    private:
        std::string _id;
        std::string _event;
        std::map<std::string, std::string> _data;

    public:
        std::string getId();
        std::string getEvent();
        std::string getDataValue(const std::string& key);
        std::map<std::string, std::string> getData();

};

#endif // BACKEND_COMPONENTSTATEEVENT_HPP
