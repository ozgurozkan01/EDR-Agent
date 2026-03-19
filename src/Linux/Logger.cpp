#include "Linux/Logger.hpp"
#include <chrono>
#include <iomanip>
#include <iostream>

void Logger::Log(LogLevel level, const std::string_view message)
{
    std::lock_guard<std::mutex> lck (logMutex);

    const auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    
    std::cout << "[" << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S") << "] "
          << "[" << LevelToString(level) << "] " << message << std::endl;
}

std::string_view Logger::LevelToString(LogLevel level)
{
    switch (level)
    {
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARNING:
            return "WARNING";
        case LogLevel::ERROR:
            return "ERROR";
        case LogLevel::DEBUG:
            return "DEBUG";
        default:
            return "UNKNOWN";
    }
}