#pragma once

#include "File.hpp"

class ProjectFiles {

    private:
        std::vector<File> _files;

    public:
        ProjectFiles();
        ~ProjectFiles() = default;

    public:
        const std::vector<File> &getFiles() const;

        void setFiles(std::vector<File> files);
};
