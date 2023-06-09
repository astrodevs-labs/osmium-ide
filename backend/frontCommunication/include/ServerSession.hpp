/*
** test_front_communication, 2023
** ServerSession.hpp by 0xMemoryGrinder
*/

#pragma once


#include <vector>
#include "ixwebsocket/IXWebSocket.h"
#include "ixwebsocket/IXConnectionState.h"

class ServerSession : public ix::ConnectionState
{

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

    public:
        ServerSession();

        ~ServerSession() override;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
    public:
        void setWs(std::shared_ptr<ix::WebSocket> ws);

        void send(std::string &message, bool binary = false);

        void close();


    private:
        std::shared_ptr<ix::WebSocket> _ws;
        static inline std::vector<ServerSession *> _sessions;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
    public:
        static void broadcast(std::string &message, bool binary = false);

        static void send(uint64_t id, std::string &message, bool binary = false);


    private:



//////////////////////--------------------------/////////////////////////

};
