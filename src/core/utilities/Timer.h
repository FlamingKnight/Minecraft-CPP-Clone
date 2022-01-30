
#ifndef MINECRAFTCLONE_TIMER_H
#define MINECRAFTCLONE_TIMER_H
#include "../../core.h"
#include <chrono>
#include "ChromeInstrumentor.h"

namespace MinecraftClone::Timing {
    struct Timer {
        std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds> startTime{};
        long long time{};
        const char* name{};

        /**
         * Once constructed, initialized startTime with the current time
         */
        explicit Timer(const char* name);
        ~Timer();

        /**
         * Made in case the same object wants to reset its startTime
         */
        void start(const char* n = "");

        /**
         * Stops by subtracting the end and start time
         */
        void stop(bool record = true);

        /**
         * @return The time it took in microseconds
         */
        [[nodiscard]] long long getTime() const;
    };
}


#endif //MINECRAFTCLONE_TIMER_H
