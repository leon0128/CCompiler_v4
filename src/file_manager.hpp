#pragma once

#include <string>

class FileManager
{
public:
    FileManager() = delete;

    static bool write(const char* filename,
                      const char* data);
    static bool write(const char* filename,
                      const std::string& data);

    static bool read(const char* filename,
                     std::string& data);

private:
    static bool openError(const char* filename);
};