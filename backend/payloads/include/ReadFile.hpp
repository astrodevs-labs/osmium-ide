#pragma once

#include <string>
#include <vector>

class ReadFile {
     public:
        ReadFile(std::string filePath);
        ~ReadFile() = default;

    private:
        std::string _filepath;
        std::vector<std::string> _data;

    public:
        const std::string &getFilePath() const;
        const std::vector<std::string> &getData() const;
};
