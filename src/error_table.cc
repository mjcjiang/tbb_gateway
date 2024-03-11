#include "error_table.h"

std::map<ErrorCode, std::string> error_table = {
    {ErrorCode::NO_ERROR, "NO ERROR"},
    {ErrorCode::FIELD_ERROR, "Message Field Check Error."},
    {ErrorCode::INVALID_USER, "Invalid User"},
    {ErrorCode::WRONG_PASSWD, "Wrong Password"},
    {ErrorCode::INVALID_INST, "Invalid Instrument {}"},
    {ErrorCode::ALREADY_LOGIN, "User Already Login"},
    {ErrorCode::BINDING_FAIL, "Failed Binding Socket"},
    {ErrorCode::ERASE_FAIL, "Failed To Erase"},
    {ErrorCode::PARSE_FAIL, "Failed To Parse Message"}};
