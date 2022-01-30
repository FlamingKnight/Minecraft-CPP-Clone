#ifndef MINECRAFTCLONE_UTILITIES_H
#define MINECRAFTCLONE_UTILITIES_H
#include "../../core.h"

namespace MinecraftClone::Utilities {
    /**
    * Just cleans up GLFW as well as prints to console
     * @param message Message to print on exit
     * @return Integer to exit from a main loop
     */
    int closeSafely(const char* message);

    struct AllocationMetrics {
        uint32 allocated = 0;
        uint32 freed = 0;

        [[nodiscard]] uint32 CurrentUsage() const;
        void log() const;
    };
    static AllocationMetrics allocMetrics{0, 0};
}


#endif //MINECRAFTCLONE_UTILITIES_H
