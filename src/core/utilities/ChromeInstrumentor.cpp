
#include "ChromeInstrumentor.h"

void MinecraftClone::Timing::ChromeInstrumentor::BeginSession(const char *name, const std::string &filepath) {
    outputStream.open(filepath);
    WriteHeader();
    session = name;
}

void MinecraftClone::Timing::ChromeInstrumentor::EndSession() {
    WriteFooter();
    outputStream.close();
    session = nullptr;
    profileCount = 0;
}

void MinecraftClone::Timing::ChromeInstrumentor::WriteProfile(const MinecraftClone::Timing::ProfileResult &profile) {
    if(profileCount++ > 0) outputStream << ", ";

    outputStream << "{";
    outputStream << R"("cat":"function",)";
    outputStream << "\"dur\":" << (profile.end - profile.start) << ',';
    outputStream << R"("name":")" << profile.name << "\",";
    outputStream << R"("ph":"X",)";
    outputStream << "\"pid\":0,";
    outputStream << "\"tid\":" << profile.threadId << ",";
    outputStream << "\"ts\":" << profile.start;
    outputStream << "}";

    outputStream.flush();
}

void MinecraftClone::Timing::ChromeInstrumentor::WriteHeader() {
    outputStream << R"({"otherData": {},"traceEvents":[)";
    outputStream.flush();
}

void MinecraftClone::Timing::ChromeInstrumentor::WriteFooter() {
    outputStream << "]}";
    outputStream.flush();
}
