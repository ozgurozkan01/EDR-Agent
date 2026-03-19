#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string_view>
#include <cstdint>
#include <mutex>
#include <string>

enum class LogLevel : uint8_t {
    INFO = 0,
    WARNING,
    ERROR,
    DEBUG
};

class Logger {
public:
    static void Log(LogLevel level, const std::string_view message);
private:
    inline static std::mutex logMutex;
    static std::string_view LevelToString(LogLevel level);
};

#endif
