#include "config_fetch.h"
#include <spdlog/spdlog.h>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/**
 * @brief get account infomation from config file
 *
 * @param config_path The path of the config file
 */
bool get_account_info(const std::string &config_path, AccountInfo& acct_info) {
    std::ifstream file(config_path);
    if (file.fail()) {
        SPDLOG_WARN("Failed to open file {}", config_path);
        return false;
    }

    json data = json::parse(file);
    acct_info.account_id = data.value("account_id", "");
    acct_info.password = data.value("password", "");
    acct_info.broker_id = data.value("broker_id", "");
    acct_info.auth_code = data.value("auth_code", "");
    acct_info.product_info = data.value("product_info", "");
    acct_info.app_id = data.value("app_id", "");
    acct_info.md_uri = data.value("md_uri", "");
    acct_info.td_uri = data.value("td_uri", "");
    
    return true;
}

/**
 * @brief get xtp config infomation from file
 *
 * @param config_path The path of the config file
 */
bool get_xtp_info(const std::string& config_path, XtpInfo& xtp_info) {
    std::ifstream file(config_path);
    if (file.fail()) {
        SPDLOG_WARN("Failed to open file {}", config_path);
    }

    json data = json::parse(file);
    xtp_info.client_id = data.at("client_id").get<uint8_t>();
    xtp_info.login_password = data.value("login_password", "");
    xtp_info.key = data.value("key", "");
    xtp_info.md_address = data.value("td_address", "");
    xtp_info.td_address = data.value("md_address", "");
        
    return true;
}
