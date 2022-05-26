#include "LoggingTypes.hpp"

bool ConsoleLogger::log(LoggingLevel log_level, const std::string& log_string)
{
    std::cout << LoggingEnumStrings[log_level] << ": " << log_string << std::endl;

    return true;
}

bool SocketLogger::log(LoggingLevel log_level, const std::string& log_string)
{
    // ToDo: Network
    std::cout << "ToDo: Socket Logger." << std::endl;

    return true;
}

std::string FileLogger::file_path = "";

bool FileLogger::log(LoggingLevel log_level, const std::string& log_string)
{
    if (file_path == "")
    {
        file_path = "./DebugLog.txt";
    }

    std::ofstream output_file;
    output_file.open(file_path, std::ios::out | std::ios::app);

    if (!output_file.is_open())
    {
        #if VERBOSE_LOGGING
            std::cout << "Failed to open the file for logging: " << file_path << std::endl;
        #endif

        return false;
    }

    output_file << LoggingEnumStrings[log_level] << ": " << log_string;

    if (output_file.fail())
    {
        #if VERBOSE_LOGGING
            std::cout << "Failed to write to the file for logging: " << file_path << std::endl;
        #endif

        return false;           
    }

    output_file.close();

    return true;
}

void FileLogger::setFilePath(const std::string& _file_path)
{
    file_path = _file_path;
}

std::string FileLogger::getFilePath()
{
    return file_path;
}