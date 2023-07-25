#include <iostream>
#include <string>
#include "custome_time.h"

/*
auto lprintdate = [](auto const & d) {std::cout << d << std::endl; };

void test_date_fmt() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    std::tm* tm = std::localtime(&time);
    std::string formatted_time = fmt::format("{:%Y-%m-%d %H:%M:%S}.{:03d}", *tm, ms.count());
    std::cout << formatted_time << std::endl;
}

void sys_days_test() {
    sys_days d1 = 2023_y / 7 / 20;
    sys_days d2 = 29_d / oct / 2023;
    sys_days d3 = oct / 29 / 2023;
    auto today = floor<days>(system_clock::now());
    lprintdate(d1);
    lprintdate(d2);
    lprintdate(d3);
    lprintdate(today);
}

void year_month_day_test() {
    year_month_day d1 = 2016_y / oct / 29;
    year_month_day d2 = 29_d / oct / 2016;
    year_month_day d3 = oct / 29 / 2016;
    year_month_day today = floor<days>(system_clock::now());

    lprintdate(d1);      // 2016-10-29
    lprintdate(d2);      // 2016-10-29
    lprintdate(d3);      // 2016-10-29
    lprintdate(today);   // 2016-10-31
}

void ymw_to_ymd_test() {
    auto wd1 = 2016_y / oct / mon[1];
    auto wd2 = mon[1] / oct / 2016;
    auto wd3 = oct / mon[1] / 2016;

    lprintdate(wd1);     // 2016/Oct/Mon[1]
    lprintdate(wd2);     // 2016/Oct/Mon[1]
    lprintdate(wd3);     // 2016/Oct/Mon[1]

    auto d1 = year_month_day{ wd1 };
    auto d2 = year_month_day{ wd2 };
    auto d3 = year_month_day{ wd2 };

    lprintdate(d1);      // 2016-10-03
    lprintdate(d2);      // 2016-10-03
    lprintdate(d3);      // 2016-10-03
}
*/

int main() {
    /*
    sys_days_test();
    year_month_day_test();
    ymw_to_ymd_test();
    */
    //test_date_fmt();
    std::string stamp;
    TimeProc::get_readable_timestamp_with_ms(stamp);
    std::cout << stamp << std::endl;

    std::cout << TimeProc::get_timestamp_in_nanoseconds() << std::endl;
    std::cout << TimeProc::get_timestamp_in_seconds() << std::endl;

    /*
    // 获取当前时间的纳秒级别时间戳
    auto ns_now = std::chrono::time_point_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now()).time_since_epoch().count();

    // 获取当前时间的微秒级别时间戳
    auto us_now = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::system_clock::now()).time_since_epoch().count();

    // 获取当前时间的毫秒级别时间戳
    auto ms_now = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()).time_since_epoch().count();

    std::cout << "Nanoseconds: " << ns_now << std::endl;
    std::cout << "Microseconds: " << us_now << std::endl;
    std::cout << "Milliseconds: " << ms_now << std::endl;
    */
    return 0;
}
