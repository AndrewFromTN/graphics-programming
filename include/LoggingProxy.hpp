#ifndef LOGGING_PROXY_H
#define LOGGING_PROXY_H

#include "LoggingEnums.hpp"
#include <tuple>

class ConsoleLogger;
class SocketLogger;
class FileLogger;

class LoggingProxy
{
    private:
        template <int N, class... Args>
        static bool _log(LoggingLevel log_level, const std::string& log_string)
        {
            return std::tuple_element<N, std::tuple<Args...>>::type::log(log_level, log_string) &&
                    _log<N - 1, Args...>(log_level, log_string);
        }

    template <class...>
    friend class LoggingService;
};

/*
 * !--------------------------! BEWARE !--------------------------!
 * 
 * The following section contains the full template specializations
 * for the different permutations of the _log function.
 * 
 * It is hideous.
 * 
 * C++ does not support partial template specialization for function
 * templates, only classes.
 * 
 * If it is ever added I will purge almost all of this section
 * with extreme prejudice.
 * 
 */

template <>
inline bool LoggingProxy::_log<-1, ConsoleLogger>(LoggingLevel log_level, const std::string& log_string)
{
    return true;
}

template <>
inline bool LoggingProxy::_log<-1, SocketLogger>(LoggingLevel log_level, const std::string& log_string)
{
    return true;
}

template <>
inline bool LoggingProxy::_log<-1, FileLogger>(LoggingLevel log_level, const std::string& log_string)
{
    return true;
}

template <>
inline bool LoggingProxy::_log<-1, ConsoleLogger, SocketLogger>(LoggingLevel log_level, const std::string& log_string)
{
    return true;
}

template <>
inline bool LoggingProxy::_log<-1, SocketLogger, ConsoleLogger>(LoggingLevel log_level, const std::string& log_string)
{
    return true;
}

template <>
inline bool LoggingProxy::_log<-1, FileLogger, SocketLogger>(LoggingLevel log_level, const std::string& log_string)
{
    return true;
}

template <>
inline bool LoggingProxy::_log<-1, SocketLogger, FileLogger>(LoggingLevel log_level, const std::string& log_string)
{
    return true;
}

template <>
inline bool LoggingProxy::_log<-1, ConsoleLogger, FileLogger>(LoggingLevel log_level, const std::string& log_string)
{
    return true;
}

template <>
inline bool LoggingProxy::_log<-1, FileLogger, ConsoleLogger>(LoggingLevel log_level, const std::string& log_string)
{
    return true;
}

template <>
inline bool LoggingProxy::_log<-1, ConsoleLogger, SocketLogger, FileLogger>(LoggingLevel log_level, const std::string& log_string)
{
    return true;
}

template <>
inline bool LoggingProxy::_log<-1, SocketLogger, ConsoleLogger, FileLogger>(LoggingLevel log_level, const std::string& log_string)
{
    return true;
}

template <>
inline bool LoggingProxy::_log<-1, FileLogger, SocketLogger, ConsoleLogger>(LoggingLevel log_level, const std::string& log_string)
{
    return true;
}

template <>
inline bool LoggingProxy::_log<-1, FileLogger, ConsoleLogger, SocketLogger>(LoggingLevel log_level, const std::string& log_string)
{
    return true;
}

template <>
inline bool LoggingProxy::_log<-1, ConsoleLogger, FileLogger, SocketLogger>(LoggingLevel log_level, const std::string& log_string)
{
    return true;
}

template <>
inline bool LoggingProxy::_log<-1, SocketLogger, FileLogger, ConsoleLogger>(LoggingLevel log_level, const std::string& log_string)
{
    return true;
}

#endif