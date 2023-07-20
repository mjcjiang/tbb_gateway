#include <iostream>
#include "date/date.h"
#include "date/tz.h"

using namespace date;
using namespace std::chrono;

int main() {
    /*
    auto today = floor<days>(system_clock::now());
    std::cout << today << std::endl;

    auto ymd = year_month_day(today);
    std::cout << ymd << std::endl;

    auto ymw = year_month_weekday(today);
    std::cout << ymw << std::endl;

    std::cout << weekday{July/4/2001} << '\n';
    std::cout << system_clock::now() << '\n';
    */

    // 获取当前系统时间
    auto now = std::chrono::system_clock::now();

    // 将时间转换为本地时间
    //auto localTime = date::make_zoned(date::current_zone(), now);

    // 格式化时间为字符串
    auto timeStr = date::format("%Y-%m %H:%M:%S", now);
    std::cout << timeStr << std::endl;

    return 0;
}
