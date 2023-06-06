#pragma once

#include <string>

class ReadFile {
     public:
        ReadFile(std::string filePath);
        ~ReadFile() = default;

    private:
        std::string _filepath;

    public:
        const std::string &getFilePath() const;
};
