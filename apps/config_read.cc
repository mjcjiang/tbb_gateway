#include <iostream>
#include "config_fetch.h"

int main() {
    AccountInfo acct_info;
    int res = get_account_info("./configs/account.json", acct_info);
    if (!res) {
        std::cout << "account_id: " << acct_info.account_id << std::endl;
    }
    return 0;
}
