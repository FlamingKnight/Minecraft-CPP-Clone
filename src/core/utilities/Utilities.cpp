#include "Utilities.h"
#include "Logger.h"

namespace MinecraftClone::Utilities {
    int closeSafely(const char* message) {
        printf(message);
        glfwTerminate();
        return -1;
    }

    [[nodiscard]] uint32 AllocationMetrics::CurrentUsage() const {
        return allocated-freed;
    }
    void AllocationMetrics::log() const {
        Logger::log(("CurrAlloc: " + std::to_string(allocated-freed)).c_str());
        Logger::log(("Allocated: " + std::to_string(allocated)).c_str());
        Logger::log(("Freed: " + std::to_string(freed)).c_str());
    }
}
