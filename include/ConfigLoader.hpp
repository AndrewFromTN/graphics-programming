#ifndef CONFIG_LOADER_H
#define CONFIG_LOADER_H

#include <map>
#include <string>

class ConfigLoader
{
    public:
        static bool LoadConfigFile(const std::string& file);

        static std::map<std::string, std::string> args;
};

#endif