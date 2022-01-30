cmake_minimum_required(VERSION 3.19)
project(MinecraftClone)

set(CMAKE_CXX_STANDARD 20)

if (DEBUG)
    add_definitions(-DDEBUG=1)
endif (DEBUG)

add_subdirectory(GLFW)
add_subdirectory(glad)
add_subdirectory(glm)
add_subdirectory(robin-hood-hashing-3.11.5)
include_directories(GLFW/include)
include_directories(glad/include)
include_directories(glm/glm)
include_directories(robin-hood-hashing-3.11.5/src/include)

file(GLOB mclone_source
        "*.h"
        "*.c"
        "*.cpp"
        )

add_executable(MinecraftClone ${mclone_source} src/main.cpp src/gabeCPPUtils.hpp src/core/Window.cpp src/core/Window.h src/core/Input.cpp src/core/Input.h src/core.h src/core/utilities/Utilities.cpp src/core/utilities/Utilities.h src/core/rendering/Shader.cpp src/core/rendering/Shader.h src/core/utilities/Logger.cpp src/core/utilities/Logger.h src/core/utilities/Timer.cpp src/core/utilities/Timer.h src/core/utilities/ChromeInstrumentor.cpp src/core/utilities/ChromeInstrumentor.h src/gabeCPPUtils.cpp src/core/rendering/ShaderProgram.cpp src/core/rendering/ShaderProgram.h src/core/challenges/ShaderExamples.cpp src/core/challenges/ShaderExamples.h)

target_link_libraries(MinecraftClone glfw ${GLFW_LIBRARIES})
target_link_libraries(MinecraftClone Glad3 ${Glad3})
target_link_libraries(MinecraftClone glm ${glm})
target_link_libraries(MinecraftClone robin_hood ${robin_hood})