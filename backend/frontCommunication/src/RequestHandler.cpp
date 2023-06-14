/*
** front-communication, 2022
** RequestHandler.cpp by 0xMemoryGrinder
*/

#include <iostream>
#include "RequestHandler.hpp"

void RequestHandler::handleMessage(std::shared_ptr<ServerSession> session, ix::WebSocket &ws, const ix::WebSocketMessagePtr &msg)
{
    if (msg->binary) {
        ws.send("Error: Invalid format", false);
        return;
    }
    json j;
    try {
        j = json::parse(msg->str);
    } catch (json::parse_error &e) {
        ws.send("Error: this is not json", false);
        return;
    }
    if (!j.contains("type")) {
        ws.send("Error: JSON is invalid: (we need type)", false);
        return;
    }
    std::string type = j["type"];
    std::transform(type.begin(), type.end(), type.begin(), ::toupper);
    auto it = _functionMap.find(type);

    if (it != _functionMap.end()) {
        it->second(j);
    } else {
        ws.send("Not yet implemented", false);
    }
}

void RequestHandler::initialQuery(json json_data)
{
    std::cout << "Initial query" << std::endl;
    std::cout << json_data.dump(4) << std::endl;
    json_data["type"] = "initialQueryResponse";
    json_data["components"] = json::object();
    json_data["components"]["id"] = "id";
    json_data["components"]["type"] = "button";
    json_data["components"]["children"] = json::array();
    json_data["components"]["props"] = json::array();
    // auto obj = json::object();
    // obj["value"] = "Hello world";
    // obj["name"] = "value";
    auto obj2 = json::parse("{\"id\":\"1\",\"type\":\"root\",\"props\":[],\"children\":[{\"id\":\"2\",\"type\":\"sidebar\",\"props\":[{\"name\":\"align\",\"value\":\"left\"}],\"children\":[{\"id\":\"3\",\"type\":\"sidebar-item\",\"props\":[{\"name\":\"title\",\"value\":\"Files\"},{\"name\":\"icon\",\"value\":\"file\"}],\"children\":[]},{\"id\":\"5\",\"type\":\"sidebar-panel\",\"props\":[{\"name\":\"expanded\",\"value\":true}],\"children\":[{\"id\":\"6\",\"type\":\"file-hierarchy\",\"props\":[{\"name\":\"files\",\"value\":[{\"name\":\"index.html\",\"type\":\"html\"},{\"name\":\"style.css\",\"type\":\"css\"},{\"name\":\"script.js\",\"type\":\"js\"},{\"name\":\"folder1\",\"type\":\"folder\",\"items\":[{\"name\":\"index.html\",\"type\":\"html\"},{\"name\":\"style.css\",\"type\":\"css\"},{\"name\":\"script.js\",\"type\":\"js\"},{\"name\":\"folder2\",\"type\":\"folder\",\"items\":[{\"name\":\"index.html\",\"type\":\"html\"},{\"name\":\"style.css\",\"type\":\"css\"},{\"name\":\"script.js\",\"type\":\"js\"}]}]}]}],\"children\":[]}]}]},{\"id\":\"4\",\"type\":\"canvas\",\"props\":[],\"children\":[{\"id\":\"7\",\"type\":\"tabs-bar\",\"props\":[],\"children\":[{\"id\":\"8\",\"type\":\"tab\",\"props\":[{\"name\":\"title\",\"value\":\"index.html\"},{\"name\":\"active\",\"value\":true}],\"children\":[]},{\"id\":\"9\",\"type\":\"tab\",\"props\":[{\"name\":\"title\",\"value\":\"style.css\"},{\"name\":\"active\",\"value\":false}],\"children\":[]},{\"id\":\"10\",\"type\":\"tab\",\"props\":[{\"name\":\"title\",\"value\":\"script.js\"},{\"name\":\"active\",\"value\":false}],\"children\":[]},{\"id\":\"10\",\"type\":\"tab\",\"props\":[{\"name\":\"title\",\"value\":\"script.js\"},{\"name\":\"active\",\"value\":false}],\"children\":[]},{\"id\":\"10\",\"type\":\"tab\",\"props\":[{\"name\":\"title\",\"value\":\"script.js\"},{\"name\":\"active\",\"value\":false}],\"children\":[]},{\"id\":\"10\",\"type\":\"tab\",\"props\":[{\"name\":\"title\",\"value\":\"script.js\"},{\"name\":\"active\",\"value\":false}],\"children\":[]},{\"id\":\"10\",\"type\":\"tab\",\"props\":[{\"name\":\"title\",\"value\":\"script.js\"},{\"name\":\"active\",\"value\":false}],\"children\":[]}]},{\"id\":\"11\",\"type\":\"editor\",\"props\":[{\"name\":\"content\",\"value\":\"YXdlc29tZSBjb2Rl\"}],\"children\":[]}]}]}");
    json_data["components"] = obj2;
    // json_data["components"]["props"].push_back(obj2);
    std::string dump = json_data.dump();
    std::cout << dump << std::endl;
    ServerSession::broadcast(dump);
}

void RequestHandler::componentInteracted(json json_data) {}
