#include <utility>

#include "ReadFile.hpp"

ReadFile::ReadFile(std::string filePath) {
    this->_filepath = std::move(filePath);
}

const std::string &ReadFile::getFilePath() const {
    return this->_filepath;
}

const std::vector<std::string> &ReadFile::getData() const {
    return this->_data;
}
