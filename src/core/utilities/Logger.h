//
// Created by asher on 12/28/2021.
//

#ifndef MINECRAFTCLONE_LOGGER_H
#define MINECRAFTCLONE_LOGGER_H

#include "../../core.h"

#if DEBUG == 1
#define PRINT_INFO(x) {\
char buf[10]; \
getTimeAsString(buf); \
std::cout << "[" << buf  << "] INFO: " << x << "\n";}

#define PRINT_WARN(x) {\
char buf[10]; \
getTimeAsString(buf); \
std::cout << "[" << buf  << "] WARNING: " << x << "\n";}

#define PRINT_ERROR(x) {\
char buf[10]; \
getTimeAsString(buf); \
std::cout << "[" << buf  << "] ERROR: " << x << "\n";}
#else
#define INFO(x)
#define WARN(x)
#define PRINT_ERROR(x)
#endif

namespace MinecraftClone {
    class Logger {
        Logger() = default;
    public:
        enum class Level : unsigned char {
            ALL = 0,
            WARNING,
            LEVEL_ERROR
        };
        static Level level;
        static void log(const char* message);
        static void info(const char* message);
        static void warn(const char* message);
        static void error(const char* message);

        static inline void getTimeAsString(char *characters);
    };
}

#endif //MINECRAFTCLONE_LOGGER_H
