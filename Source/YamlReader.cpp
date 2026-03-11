// Example YamlReader implementation using yaml-cpp
#include "YamlReader.h"
#include <yaml-cpp/yaml.h>
#include <iostream>

bool YamlReader::readFile(const std::string& path)
{
    try
    {
        YAML::Node root = YAML::LoadFile(path);

        if (root.IsScalar())
            std::cout << "Scalar: " << root.as<std::string>() << std::endl;
        else if (root.IsSequence())
        {
            std::cout << "Sequence with " << root.size() << " elements:\n";
            for (std::size_t i = 0; i < root.size(); ++i)
            {
                const YAML::Node& e = root[i];
                if (e.IsScalar())
                    std::cout << "  - " << e.as<std::string>() << std::endl;
            }
        }
        else if (root.IsMap())
        {
            std::cout << "Map:\n";
            for (const auto& kv : root)
            {
                const YAML::Node& key = kv.first;
                const YAML::Node& val = kv.second;
                std::cout << "  " << key.as<std::string>() << ": ";
                if (val.IsScalar())
                    std::cout << val.as<std::string>();
                else if (val.IsSequence())
                    std::cout << "[sequence]";
                else if (val.IsMap())
                    std::cout << "{map}";
                std::cout << std::endl;
            }
        }

        return true;
    }
    catch (const YAML::Exception& e)
    {
        std::cerr << "YAML load error: " << e.what() << std::endl;
        return false;
    }
}

bool YamlReader::readString(const std::string& yamlText)
{
    try
    {
        YAML::Node root = YAML::Load(yamlText);

        if (root.IsScalar())
            std::cout << "Scalar: " << root.as<std::string>() << std::endl;
        else if (root.IsSequence())
        {
            std::cout << "Sequence with " << root.size() << " elements:\n";
            for (std::size_t i = 0; i < root.size(); ++i)
            {
                const YAML::Node& e = root[i];
                if (e.IsScalar())
                    std::cout << "  - " << e.as<std::string>() << std::endl;
            }
        }
        else if (root.IsMap())
        {
            std::cout << "Map:\n";
            for (const auto& kv : root)
            {
                const YAML::Node& key = kv.first;
                const YAML::Node& val = kv.second;
                std::cout << "  " << key.as<std::string>() << ": ";
                if (val.IsScalar())
                    std::cout << val.as<std::string>();
                else if (val.IsSequence())
                    std::cout << "[sequence]";
                else if (val.IsMap())
                    std::cout << "{map}";
                std::cout << std::endl;
            }
        }

        return true;
    }
    catch (const YAML::Exception& e)
    {
        std::cerr << "YAML parse error: " << e.what() << std::endl;
        return false;
    }
}
