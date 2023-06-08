#include <utility>

#include "ReadFile.hpp"

ReadFile::ReadFile(std::string filePath) {
    this->_filepath = std::move(filePath);
}

const std::string &ReadFile::getFilePath() const {
    return this->_filepath;
}

const std::string &ReadFile::getData() const {
    return this->_data;
}

void ReadFile::setData(std::string data) {
    this->_data = std::move(data);
}
