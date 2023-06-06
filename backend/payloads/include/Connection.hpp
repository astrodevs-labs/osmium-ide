#pragma once

#include <string>

class Connection {

    enum BuildType {
        Debug,
        Release,
        Experimental
    };

    public:
        Connection(std::string ip, int port, bool isOwner, BuildType build, std::string version);
        ~Connection() = default;

    private:
        std::string _ip;
        int _port;
        bool _isOwner;
        BuildType _build;
        std::string _version;


    public:
        const std::string &geIp() const;
        int getPort() const;
        bool isOwner() const;
        BuildType getBuild() const;
        const std::string &getVersion() const;

};
