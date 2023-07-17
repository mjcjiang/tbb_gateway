#include "ctp_market.h"
#include <iostream>

int main(void) {
    Test test("zhangjiang");
    std::cout << test.get_name() << std::endl;
    return 0;
}
