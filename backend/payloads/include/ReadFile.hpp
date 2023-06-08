#pragma once

#include <string>
#include <vector>

class ReadFile {
     public:
        ReadFile(std::string filePath);
        ~ReadFile() = default;

    private:
        std::string _filepath;
        std::string _data;

    public:
        const std::string &getFilePath() const;
        const std::string &getData() const;

        void setData(std::string data);
};
