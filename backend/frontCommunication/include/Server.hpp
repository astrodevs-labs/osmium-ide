/*
** test_front_communication, 2023
** Server.hpp by 0xMemoryGrinder
*/

#pragma once

#include "ixwebsocket/IXWebSocketServer.h"
#include "ServerSession.hpp"

class Server
{

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

    public:
        explicit Server(int port = 0, std::string host = "0.0.0.0");

        ~Server();


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
    public:


    private:
        int _port;
        std::unique_ptr<ix::WebSocketServer> _server;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
    public:
        void run();
        int listen();

    private:
        void _onReceive(std::shared_ptr<ix::ConnectionState> state, ix::WebSocket &ws, const ix::WebSocketMessagePtr &msg);

        void _onConnectionOpen(std::weak_ptr<ix::WebSocket> ws, std::shared_ptr<ix::ConnectionState> state);
        void _onOpen(std::shared_ptr<ix::ConnectionState> state, ix::WebSocket &ws);
        void _onMessage(std::shared_ptr<ix::ConnectionState> state, ix::WebSocket &ws, const ix::WebSocketMessagePtr &msg);
        void _onClose(std::shared_ptr<ix::ConnectionState> state, ix::WebSocket &ws, const ix::WebSocketMessagePtr &msg);


//////////////////////--------------------------/////////////////////////

};
