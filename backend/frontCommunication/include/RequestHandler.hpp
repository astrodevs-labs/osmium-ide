/*
** front-communication, 2023
** RequestHandler.hpp by 0xMemoryGrinder
*/

#pragma once

#include "json.hpp"
#include "ServerSession.hpp"

using json = nlohmann::json;

class RequestHandler
{

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

    public:
        RequestHandler() = default;

        ~RequestHandler() = default;


        enum ResponseCode {
            SUCCESS = 0,
            INVALID_REQUEST = 1,
            INVALID_PARAMETER = 2,
            INTERNAL_ERROR = 3,
            NOT_IMPLEMENTED = 4
        };

//////////////////////--------------------------/////////////////////////


/////////////////////////////// METHODS /////////////////////////////////
    public:
        static void handleMessage(std::shared_ptr<ServerSession> session, ix::WebSocket &ws, const ix::WebSocketMessagePtr &msg);


        static void initialQuery(json json_data);

        static void componentInteracted(json json_data);

    private:


//////////////////////--------------------------/////////////////////////

///////////////////////////// PROPERTIES ////////////////////////////////
    public:


    private:
        static inline const std::map<std::string, std::function<void(json)>> _functionMap = {
                {"INITIALQUERY", &RequestHandler::initialQuery},
                {"COMPONENTINTERACTED", &RequestHandler::componentInteracted}
        };;

//////////////////////--------------------------/////////////////////////

};
