/*
** test_front_communication, 2022
** ServerSession.cpp by 0xMemoryGrinder
*/


#include <iostream>
#include "ServerSession.hpp"

ServerSession::ServerSession() : _ws(nullptr)
{
    _sessions.push_back(this);
    std::cerr << "New session " << _id << std::endl;
}

ServerSession::~ServerSession()
{
    _sessions.erase(std::remove(_sessions.begin(), _sessions.end(), this), _sessions.end());
    std::cerr << "Session deleted " << _id << std::endl;
}

void ServerSession::setWs(std::shared_ptr<ix::WebSocket> ws)
{
    _ws = ws;
}

void ServerSession::send(std::string &message, bool binary)
{
    if (_ws) {
        _ws->send(message, binary);
    }
}

void ServerSession::broadcast(std::string &message, bool binary)
{
    for (auto session: _sessions) {
        session->send(message, binary);
    }
}

void
ServerSession::send(uint64_t id, std::string &message, bool binary)
{
    auto idStr = std::to_string(id);

    for (auto session: _sessions) {
        if (session->_id == idStr) {
            session->send(message, binary);
            break;
        }
    }
}

void ServerSession::close()
{
    std::cerr << "Session closed " << _id << std::endl;
}
