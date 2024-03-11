/**
 * @file error_table.h
 * @brief define error codes and error messages
 * 
 * @date 2023-07-24
 */

#ifndef ERROR_TBL_H
#define ERROR_TBL_H

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
    ERASE_FAIL,
    PARSE_FAIL
};

extern std::map<ErrorCode, std::string> error_table;

#endif //ERROR_TBL_H
