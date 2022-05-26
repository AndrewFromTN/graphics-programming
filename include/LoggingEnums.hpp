#ifndef LOGGING_ENUMS_H
#define LOGGING_ENUMS_H

#include <string>
#include <vector>

enum LoggingLevel 
{
    SUCCESS, INFO,
    WARNING, MINOR_FAILURE,
    MAJOR_FAILURE, CATASTROPHIC_FAILURE
};

extern const std::string LoggingEnumStrings[6];

#endif