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

enum class ErrorCode {
    NO_ERROR,
    FIELD_ERROR,
    INVALID_USER,
    WRONG_PASSWD,
    INVALID_INST,
    ALREADY_LOGIN,
    BINDING_FAIL,
    ERASE_FAIL
};

using ErrorTable = std::map<ErrorCode, std::string>;
ErrorTable error_table = {
    {ErrorCode::NO_ERROR, "NO ERROR"},
    {ErrorCode::FIELD_ERROR, "Message Field Check Error."},
    {ErrorCode::INVALID_USER, "Invalid User"},
    {ErrorCode::WRONG_PASSWD, "Wrong Password"},
    {ErrorCode::INVALID_INST, "Invalid Instrument {}"},
    {ErrorCode::ALREADY_LOGIN, "User Already Login"},
    {ErrorCode::BINDING_FAIL, "Failed Binding Socket"},
    {ErrorCode::ERASE_FAIL, "Failed To Erase"}};

#endif //ERROR_TABLE_H
