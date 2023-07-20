/**
 * @file custome_time.h
 * @brief some time and date processing
 *
 * @date 2023-07-19
 */

#include <ctime>
#include <chrono>
#include <string>
#include <cstdint>
#include "fmt/core.h"
#include "fmt/chrono.h"

using namespace std::chrono;

class TimeProc {
 public:
    static inline std::string get_readable_timestamp_with_ms() {
        auto now = system_clock::now();
        auto time = system_clock::to_time_t(now);
        auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;
        
        std::tm* tm = std::localtime(&time);
        return fmt::format("{:%Y-%m-%d %H:%M:%S}.{:03d}", *tm, ms.count());
    }

    static inline int64_t get_timestamp_in_nanoseconds() {
        return time_point_cast<nanoseconds>(system_clock::now()).time_since_epoch().count();
    }

    static inline int64_t get_timestamp_in_microseconds() {
        return time_point_cast<microseconds>(system_clock::now()).time_since_epoch().count();
    }

    static inline int64_t get_timestamp_in_milliseconds() {
        return time_point_cast<milliseconds>(system_clock::now()).time_since_epoch().count();
    }
};
