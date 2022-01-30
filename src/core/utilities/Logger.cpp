//
// Created by asher on 12/28/2021.
//

#include "Logger.h"

namespace MinecraftClone {

    Logger::Level Logger::level;

    void Logger::log(const char* message) {
        char buf[10];
        getTimeAsString(buf);
        std::cout << "[" << buf  << "] LOG: " << message << "\n";
    }

    void Logger::info(const char* message) {
        if(level == Level::ALL)
            PRINT_INFO(message);
    }

    void Logger::warn(const char* message) {
        if(level <= Level::WARNING)
            PRINT_WARN(message);
    }

    void Logger::error(const char* message) {
        PRINT_ERROR(message);
    }

    void Logger::getTimeAsString(char* characters) {
        time_t now = time(nullptr);
        strftime(characters, 10, "%X", localtime(&now));
    }
}