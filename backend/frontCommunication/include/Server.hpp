/*
** test_front_communication, 2023
** Server.hpp by 0xMemoryGrinder
*/

#pragma once


#include "App.h"
#include "ServerSession.hpp"

class Server
{

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

    public:
        Server();

        ~Server() = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
    public:


    private:
        uWS::App _server;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
    public:
        void run();
        int listen(int port);




    private:
        void _onOpen(uWS::WebSocket<false, true, std::shared_ptr<ServerSession>> *ws);
        void _onMessage(uWS::WebSocket<false, true, std::shared_ptr<ServerSession>> *ws, std::string_view message, uWS::OpCode opCode);
        void _onClose(uWS::WebSocket<false, true, std::shared_ptr<ServerSession>> *ws, int code, std::string_view message);


//////////////////////--------------------------/////////////////////////

};
