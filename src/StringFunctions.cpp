#include "StringFunctions.hpp"

std::string insert_at_all_occurences(const std::string& input, const char find, const std::string& insert)
{
    std::string to_return = input;

    size_t pos = to_return.find(find);
    while (pos != std::string::npos)
    {
        to_return.insert(pos + 1, insert);
        pos = to_return.find(find, pos + 1);
    }

    return to_return;
}