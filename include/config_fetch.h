/**
 * @file config_fetch.h
 * @brief read system config from json file(s)
 *
 * As the running system need some configs to work, we store
 * all the configs in json files. This this the interface to
 * read or write this json files.
 *
 * @date 2023-07-18
 */

#ifndef CONFIG_FETCH_H
#define CONFIG_FETCH_H

#include <map>
#include <string>

struct AccountInfo {
    std::string account_id;
    std::string password;
    std::string broker_id;
    std::string auth_code;
    std::string product_info;
    std::string app_id;
    std::string md_uri;
    std::string td_uri;
};

int get_account_info(const std::string &config_path, AccountInfo& acct_info);

#endif // CONFIG_FETCH_H
