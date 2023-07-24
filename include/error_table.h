/**
 * @file error_table.h
 * @brief define error codes and error messages
 * 
 * @date 2023-07-24
 */

#ifndef ERROR_TABLE_H
#define ERROR_TABLE_H

#include <string>
#include <map>

using ErrorTable = std::map<int, std::string>;
ErrorTable error_table = {
    {0, "NO ERROR"},
    {1, "Message Field Check Error."},
    {2, "Invalid User"},
    {3, "Wrong Password"},
    {4, "Invalid Instrument {}"}
};

#endif //ERROR_TABLE_H
