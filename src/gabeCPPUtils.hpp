// ===================================================================================
// Headers
// ===================================================================================
#ifndef GABE_CPP_UTILS_H
#define GABE_CPP_UTILS_H
#include <cstdint>
#include <cstddef>

// ----------------------------------
// Memory Utils
// ----------------------------------

#define g_memory_allocate(numBytes) _g_memory_allocate(__FILE__, __LINE__, numBytes)
#define g_memory_realloc(memory, newSize) _g_memory_realloc(__FILE__, __LINE__, memory, newSize)
#define g_memory_free(memory) _g_memory_free(__FILE__, __LINE__, memory)

void* _g_memory_allocate(const char* filename, int line, size_t numBytes);
void* _g_memory_realloc(const char* filename, int line, void* memory, size_t newSize);
void _g_memory_free(const char* filename, int line, void* memory);

void g_memory_init(bool detectMemoryLeaks, uint16_t bufferPadding = 5);
void g_memory_dumpMemoryLeaks();

int g_memory_compareMem(void* a, void* b, size_t numBytes);
void g_memory_zeroMem(void* memory, size_t numBytes);
void g_memory_copyMem(void* dst, void* src, size_t numBytes);

// ----------------------------------
// Logging Utils
// ----------------------------------
enum g_logger_level
{
    All = 0,
    Log = 1,
    Info = 2,
    Warning = 3,
    Error = 4,
    Assert = 5,
    None = 6,
};

#if !(defined(__GNUC__) || defined(__GNUG__))
#define g_logger_log(format, ...) _g_logger_log(__FILE__, __LINE__, format, __VA_ARGS__)
#define g_logger_info(format, ...) _g_logger_info(__FILE__, __LINE__, format, __VA_ARGS__)
#define g_logger_warning(format, ...) _g_logger_warning(__FILE__, __LINE__, format, __VA_ARGS__)
#define g_logger_error(format, ...) _g_logger_error(__FILE__, __LINE__, format, __VA_ARGS__)
#define g_logger_assert(condition, format, ...) _g_logger_assert(__FILE__, __LINE__, condition, format, __VA_ARGS__)
#else
#define g_logger_log(format, ...) _g_logger_log(__FILE__, __LINE__, format,##__VA_ARGS__)
#define g_logger_info(format, ...) _g_logger_info(__FILE__, __LINE__, format,##__VA_ARGS__)
#define g_logger_warning(format, ...) _g_logger_warning(__FILE__, __LINE__, format,##__VA_ARGS__)
#define g_logger_error(format, ...) _g_logger_error(__FILE__, __LINE__, format,##__VA_ARGS__)
#define g_logger_assert(condition, format, ...) _g_logger_assert(__FILE__, __LINE__, condition, format,##__VA_ARGS__)
#endif


void _g_logger_log(const char* filename, int line, const char* format, ...);
void _g_logger_info(const char* filename, int line, const char* format, ...);
void _g_logger_warning(const char* filename, int line, const char* format, ...);
void _g_logger_error(const char* filename, int line, const char* format, ...);
void _g_logger_assert(const char* filename, int line, int condition, const char* format, ...);

void g_logger_set_level(g_logger_level level);
g_logger_level g_logger_get_level();

// ===================================================================================
// Implementation
// ===================================================================================
#include <memory>
#include <vector>
#include <mutex>
#include <stdio.h>
#ifndef __linux__
//#include <varargs.h>
#endif
#include <stdarg.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <array>
#include <algorithm>
#include <cstring>

#ifdef _WIN32
#include <Windows.h>
#include <crtdbg.h>
#endif

#endif // GABE_CPP_UTILS_H