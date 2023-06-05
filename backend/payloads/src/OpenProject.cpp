#include <utility>

#include "OpenProject.hpp"

OpenProject::OpenProject(std::string project) {
    this->_project = std::move(project);
}

const std::string &OpenProject::getProject() const
{
    return this->_project;
}
