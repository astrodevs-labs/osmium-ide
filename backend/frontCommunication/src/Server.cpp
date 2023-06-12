/*
** test_front_communication, 2022
** Server.cpp by 0xMemoryGrinder
*/


#include <iostream>
#include "Server.hpp"
#include "ixwebsocket/IXGetFreePort.h"
#include "RequestHandler.hpp"

Server::Server(int port, std::string host) : _port(port ? port: ix::getFreePort())
{
    _server = std::make_unique<ix::WebSocketServer>(_port, host);

    _server->setConnectionStateFactory([this]() {
        return std::make_shared<ServerSession>();
    });

    _server->setOnConnectionCallback([this](auto ws, auto state) {
        this->_onConnectionOpen(ws, state);
        std::shared_ptr<ix::WebSocket> wsPtr = ws.lock();
        wsPtr->setOnMessageCallback([this, wsPtr, state](auto &msg) {
            _onReceive(state, *wsPtr, msg);
        });
    });

   /* _server->setOnClientMessageCallback([this](auto state, auto &ws, auto &msg) {
        if (msg->type == ix::WebSocketMessageType::Open) {
            this->_onOpen(state, ws);
        } else if (msg->type == ix::WebSocketMessageType::Close) {
            this->_onClose(state, ws, msg);
        } else if (msg->type == ix::WebSocketMessageType::Message) {
            this->_onMessage(state, ws, msg);
        }
    });*/

}

void Server::run()
{
    _server->start();
}

int Server::listen()
{
    _server->listen();
    return _port;
}

void Server::_onReceive(std::shared_ptr<ix::ConnectionState> state,
                        ix::WebSocket &ws, const ix::WebSocketMessagePtr &msg)
{
    if (msg->type == ix::WebSocketMessageType::Open) {
        this->_onOpen(state, ws);
    } else if (msg->type == ix::WebSocketMessageType::Close) {
        this->_onClose(state, ws, msg);
    } else if (msg->type == ix::WebSocketMessageType::Message) {
        this->_onMessage(state, ws, msg);
    }
}

void Server::_onConnectionOpen(std::weak_ptr<ix::WebSocket> ws,
                               std::shared_ptr<ix::ConnectionState> state)
{
    auto session = std::dynamic_pointer_cast<ServerSession>(state);
    session->setWs(ws.lock());
}

void
Server::_onOpen(std::shared_ptr<ix::ConnectionState> state, ix::WebSocket &ws)
{

}

void Server::_onMessage(std::shared_ptr<ix::ConnectionState> state,
                        ix::WebSocket &ws, const ix::WebSocketMessagePtr &msg)
{
    RequestHandler::handleMessage(std::dynamic_pointer_cast<ServerSession>(state), ws, msg);
}

void
Server::_onClose(std::shared_ptr<ix::ConnectionState> state, ix::WebSocket &ws,
                 const ix::WebSocketMessagePtr &msg)
{

}
