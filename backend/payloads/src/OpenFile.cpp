#include <utility>
#include "OpenFile.hpp"

OpenFile::OpenFile(std::string filePath) {
    this->_filepath = std::move(filePath);
}

const std::string &OpenFile::getFilePath() const {
    return this->_filepath;
}
