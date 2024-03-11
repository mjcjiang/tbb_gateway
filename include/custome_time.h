/**
 * @file custome_time.h
 * @brief some time and date processing
 *
 * @date 2023-07-19
 */

#ifndef CUSTOME_TIME_H
#define CUSTOME_TIME_H

#include <ctime>
#include <cstdint>
#include <chrono>
#include <string>

using namespace std::chrono;

class TimeProc {
public:
    static inline void get_readable_timestamp_with_ms(std::string &stamp) {
        // Get the current system time as a time_t value
        time_t time_now;
        time(&time_now);

        // Convert time_t to a struct tm (broken down time)
        struct tm* tm_now;
        tm_now = localtime(&time_now);

        // Extract the milliseconds component from the current time
        struct timespec ts;
        timespec_get(&ts, TIME_UTC);
        long milliseconds = ts.tv_nsec / 1000000;

        // Output the date and time in the desired format
        char formatted_time[30];
        sprintf(formatted_time, "%04d-%02d-%02d %02d:%02d:%02d.%03ld\n", 
                tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday,
                tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec, milliseconds);

        stamp = formatted_time;
    }

    static inline uint64_t get_timestamp_in_nanoseconds() {
        return time_point_cast<nanoseconds>(system_clock::now()).time_since_epoch().count();
    }

    static inline uint64_t get_timestamp_in_microseconds() {
        return time_point_cast<microseconds>(system_clock::now()).time_since_epoch().count();
    }

    static inline uint64_t get_timestamp_in_milliseconds() {
        return time_point_cast<milliseconds>(system_clock::now()).time_since_epoch().count();
    }

    static inline uint64_t get_timestamp_in_seconds() {
        return time_point_cast<seconds>(system_clock::now()).time_since_epoch().count();
    }
};

#endif //CUSTOME_TIME_H
