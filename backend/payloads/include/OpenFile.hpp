#pragma once

#include <string>

class OpenFile {
     public:
        OpenFile(std::string filePath);
        ~OpenFile() = default;

    private:
        std::string _filepath;

    public:
        const std::string &getFilePath() const;
};

