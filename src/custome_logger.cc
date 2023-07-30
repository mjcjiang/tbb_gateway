#include "custome_logger.h"
#include "spdlog/sinks/daily_file_sink.h"

void set_default_daily_logger(const std::string &name) {
    if (spdlog::default_logger()->name().empty()) {
        auto daily_logger = spdlog::daily_logger_mt(name, "logs/" + name + ".log", 0, 0);
        daily_logger->flush_on(spdlog::level::info);
        daily_logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%s:%#] %v");
        spdlog::set_default_logger(daily_logger);
    }
}
