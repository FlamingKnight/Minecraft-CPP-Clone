
#include "Timer.h"

namespace MinecraftClone::Timing {
    Timer::Timer(const char* name) {
        start(name);
    }

    void Timer::start(const char* n) {
        startTime = std::chrono::high_resolution_clock::now();
        this->name = n;
    }

    void Timer::stop(bool record) {
        long long start = std::chrono::time_point_cast<std::chrono::microseconds>(startTime).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();
        time = end-start;
        uint32_t threadId = std::hash<std::thread::id>{}(std::this_thread::get_id());

        if(record)
            ChromeInstrumentor::Get().WriteProfile({name, start, end, threadId});
    }

    long long Timer::getTime() const {
        return time;
    }

    Timer::~Timer() {
        stop(false);
    }
}