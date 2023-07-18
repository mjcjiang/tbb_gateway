#include "config_fetch.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/**
 * @brief get account infomation from config file
 *
 * @param config_path The path of the config file
 */
int get_account_info(const std::string &config_path, AccountInfo& acct_info) {
    std::ifstream file(config_path);
    if (file.fail()) {
        std::cout << "Fail to open the file..." << std::endl;
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
    
    return 0;
}
