#pragma once

#include <string>

class YamlReader
{
public:
    // Load YAML from a file and print a few example values to stdout.
    static bool readFile(const std::string& path);

    // Load YAML from a string and print a few example values to stdout.
    static bool readString(const std::string& yamlText);
};
