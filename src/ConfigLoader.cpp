#include "ConfigLoader.hpp"
#include "LoggingService.hpp"
#include "StringFunctions.hpp"

#include <fstream>

std::map<std::string, std::string> ConfigLoader::args;

bool ConfigLoader::LoadConfigFile(const std::string& file)
{
    LoggingService<FileLogger> logger;

    std::ifstream file_stream;

    file_stream.open(file, std::fstream::in);

    if (file_stream.fail() || file_stream.bad())
    {
        logger.log(LoggingLevel::MAJOR_FAILURE, "Failed to read config file: " + file);
    }

    std::string line;
    std::string attribute;
    while (std::getline(file_stream, attribute, '='))
    {
        if (std::getline(file_stream, line))
        {
            args[attribute] = line;
        }
    }

    #if VERBOSE_LOGGING
        logger.log(LoggingLevel::SUCCESS, "Config file loaded.\n");

        file_stream.clear();
        file_stream.seekg(0, std::ios::beg);
        std::string file_contents((std::istreambuf_iterator<char>(file_stream)), 
                                   std::istreambuf_iterator<char>());

        file_contents = insert_at_all_occurences(file_contents, '\n', "\t");
        file_contents.insert(0, "\t");
        logger.log(LoggingLevel::INFO, "Config file contents:\n\n" + file_contents + "\n\n");
    #endif

    std::string separator = (args.at("SYSTEM_TYPE") == "Windows") ? "\\" : "/";
    args.at("SHADER_DIR") = args.at("ENGINE_HOME") + separator + args.at("SHADER_DIR") + separator;

    file_stream.close();

    return true;
}

