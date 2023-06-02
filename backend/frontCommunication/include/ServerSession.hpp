/*
** test_front_communication, 2023
** ServerSession.hpp by 0xMemoryGrinder
*/

#pragma once


#include <vector>
#include "WebSocket.h"

class ServerSession
{

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

    public:
        ServerSession();

        ~ServerSession();


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
    public:
        void setWs(uWS::WebSocket<false, true, std::shared_ptr<ServerSession>> *ws);

        void send(std::string_view message, uWS::OpCode opCode = uWS::OpCode::TEXT);

        void close();


    private:
        uint32_t _id;
        uWS::WebSocket<false, true, std::shared_ptr<ServerSession>> *_ws;

        static inline uint32_t _idCounter = 0;
        static inline std::vector<ServerSession *> _sessions;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
    public:
        static void broadcast(std::string_view message, uWS::OpCode opCode = uWS::OpCode::TEXT);

        static void send(uint32_t id, std::string_view message, uWS::OpCode opCode = uWS::OpCode::TEXT);


    private:



//////////////////////--------------------------/////////////////////////

};
