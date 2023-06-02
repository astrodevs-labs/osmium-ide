/*
** test_front_communication, 2022
** Server.cpp by 0xMemoryGrinder
*/


#include "Server.hpp"

Server::Server()
{
    _server.ws<std::shared_ptr<ServerSession>>("/*", {
            .compression = uWS::CompressOptions(uWS::DEDICATED_COMPRESSOR_4KB | uWS::DEDICATED_DECOMPRESSOR),
            .maxPayloadLength = 100 * 1024 * 1024,
            .idleTimeout = 16,
            .maxBackpressure = 100 * 1024 * 1024,
            .closeOnBackpressureLimit = false,
            .resetIdleTimeoutOnSend = false,
            .sendPingsAutomatically = true,
            /* Handlers */
            .upgrade = nullptr,

            .open = [this](auto *ws) {
                this->_onOpen(ws);
            },
            .message = [this](auto *ws, std::string_view message, uWS::OpCode opCode) {
                this->_onMessage(ws, message, opCode);
            },
            .close = [this](auto *ws, int code, std::string_view message) {
                this->_onClose(ws, code, message);
            },
    });
}

void Server::run()
{
    _server.run();
}

int Server::listen(int port)
{
    _server.listen(port, [&port](auto *listen_socket) {
        if (listen_socket) {
            std::cout << "Listening on port " << 9001 << std::endl;
        }
    });
    return port;
}

void Server::_onOpen(uWS::WebSocket<false, true, std::shared_ptr<ServerSession>> *ws)
{
    auto data = ws->getUserData();
    *data = std::make_shared<ServerSession>();
    (*data)->setWs(ws);
    std::cout << "New connection" << std::endl;
}

void Server::_onMessage(uWS::WebSocket<false, true, std::shared_ptr<ServerSession>> *ws,
                        std::string_view message, uWS::OpCode opCode)
{
    std::cout << "New message" << message << std::endl;
    ServerSession::broadcast(message, opCode);
}

void Server::_onClose(uWS::WebSocket<false, true, std::shared_ptr<ServerSession>> *ws, int code,
                      std::string_view message)
{
    std::cout << "Connection closed" << std::endl;
//    (*ws->getUserData())->close();
}
