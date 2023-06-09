/*
** front-communication, 2022
** RequestHandler.cpp by 0xMemoryGrinder
*/


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

}

void RequestHandler::componentInteracted(json json_data)
{

}
