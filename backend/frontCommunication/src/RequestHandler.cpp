/*
** front-communication, 2022
** RequestHandler.cpp by 0xMemoryGrinder
*/


#include <iostream>
#include "RequestHandler.hpp"

void RequestHandler::handleMessage(std::shared_ptr<ServerSession> session,
                                   ix::WebSocket &ws,
                                   const ix::WebSocketMessagePtr &msg)
{
    if (msg->binary) {
        ws.send("Error: Invalid format", false);
        return;
    }
    json j;
    try {
        j = json::parse(msg->str);
    }
    catch (json::parse_error& e) {
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
    }
    else {
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
    std::string dump = json_data.dump();
    std::cout << dump << std::endl;
    ServerSession::broadcast(dump);
}

void RequestHandler::componentInteracted(json json_data)
{

}
