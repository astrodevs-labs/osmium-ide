#include <string>
#include <vector>

enum FileType {
    FILE,
    DIRECTORY
}

struct File;

struct File {
    std::string filePath;
    std::string name;
    FileType type;
    bool isReadable;
    bool isWritable;
    bool isExecutable;
    std::vector<File> children;
}
