#include "ProjectFiles.hpp"

ProjectFiles::ProjectFiles() = default;

const std::vector<File> &ProjectFiles::getFiles() const {
    return this->_files;
}

void ProjectFiles::setFiles(std::vector<File> files) {
    this->_files = std::move(files);
}
