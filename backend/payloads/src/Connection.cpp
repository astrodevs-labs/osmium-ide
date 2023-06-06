#include <utility>

#include "Connection.hpp"

Connection::Connection(std::string ip, int port, bool isOwner, BuildType build, std::string version) {
    this->_ip = std::move(ip);
    this->_port = port;
    this->_isOwner = isOwner;
    this->_build = build;
    this->_version = std::move(version);
}

const std::string &Connection::geIp() const {
    return this->_ip;
}

int Connection::getPort() const {
    return this->_port;
}

bool Connection::isOwner() const {
    return this->_isOwner;
}

Connection::BuildType Connection::getBuild() const {
    return this->_build;
}

const std::string &Connection::getVersion() const {
    return this->_version;
}
