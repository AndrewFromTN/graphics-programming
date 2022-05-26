#ifndef LOGGING_SERVICE_H
#define LOGGING_SERVICE_H

#include <iostream>
#include <string>
#include <tuple>
#include <type_traits>
#include <algorithm>

#include "LoggingEnums.hpp"
#include "LoggingProxy.hpp"
#include "GlobalDefines.hpp"
#include "LoggingTypes.hpp"

template <class... Args>
class LoggingService
{
    public:
        bool log(LoggingLevel log_level, const std::string& log_string)
        {
            const auto tuple_size = std::tuple_size<std::tuple<Args...>>::value;

            return LoggingProxy::_log<tuple_size - 1, Args...>(log_level, log_string);
        }

        void setFileOutput(const std::string& file_path)
        {
            FileLogger::setFilePath(file_path);
        }
};

#endif