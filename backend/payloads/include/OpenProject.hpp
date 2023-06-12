#pragma once

#include <string>

class OpenProject
{
    public:
        OpenProject(std::string project);
        ~OpenProject() = default;

    private:
        std::string _project;

    public:
        const std::string &getProject() const;

};
