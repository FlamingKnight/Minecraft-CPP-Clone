
#ifndef MINECRAFTCLONE_CHROMEINSTRUMENTOR_H
#define MINECRAFTCLONE_CHROMEINSTRUMENTOR_H

#include <fstream>
#include "../../core.h"

namespace MinecraftClone::Timing {
    struct ProfileResult {
        const char* name;
        long long start, end;
        uint32_t threadId;
    };

    class ChromeInstrumentor {
    private:
        const char* session;
        std::ofstream outputStream;
        int profileCount;

    public:
        ChromeInstrumentor(const ChromeInstrumentor& instrumentor) = delete;
        explicit ChromeInstrumentor() : session(nullptr), profileCount(0) {}

        void BeginSession(const char* name, const std::string& filepath = "trace.json");
        void EndSession();
        void WriteProfile(const ProfileResult& profile);

        void WriteHeader();
        void WriteFooter();

        static ChromeInstrumentor& Get() {
            static ChromeInstrumentor instrumentor;
            return instrumentor;
        }
    };
}


#endif //MINECRAFTCLONE_CHROMEINSTRUMENTOR_H
