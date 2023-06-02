/*
** test_front_communication, 2022
** ServerSession.cpp by 0xMemoryGrinder
*/


#include <iostream>
#include "ServerSession.hpp"

ServerSession::ServerSession() : _id(_idCounter++), _ws(nullptr)
{
    _sessions.push_back(this);
    std::cerr << "New session " << _id << std::endl;
}

ServerSession::~ServerSession()
{
    _sessions.erase(std::remove(_sessions.begin(), _sessions.end(), this), _sessions.end());
    std::cerr << "Session deleted " << _id << std::endl;
}

void ServerSession::setWs(uWS::WebSocket<false, true, std::shared_ptr<ServerSession>> *ws)
{
    _ws = ws;
}

void ServerSession::send(std::string_view message, uWS::OpCode opCode)
{
    if (_ws) {
        _ws->send(message, opCode);
    }
}

void ServerSession::broadcast(std::string_view message, uWS::OpCode opCode)
{
    for (auto session: _sessions) {
        session->send(message, opCode);
    }
}

void
ServerSession::send(uint32_t id, std::string_view message, uWS::OpCode opCode)
{
    for (auto session: _sessions) {
        if (session->_id == id) {
            session->send(message, opCode);
            break;
        }
    }
}

void ServerSession::close()
{
    std::cerr << "Session closed " << _id << std::endl;
}
