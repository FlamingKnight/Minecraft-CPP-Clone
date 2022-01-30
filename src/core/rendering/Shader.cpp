//
// Created by asher on 12/24/2021.
//

#include <fstream>
#include "Shader.h"
#include "../utilities/Logger.h"
namespace MinecraftClone {

    bool Shader::compile(ShaderType type, const char* shaderFilePath) {
        //Let's read the shader's file
        int strLength = (int)std::strlen(shaderFilePath);
        filePath = (char*) g_memory_allocate(sizeof(char) * (strLength+1));
        std::strcpy(filePath, shaderFilePath);
        filePath[strLength] = '\0';
        g_logger_info("Compiling shader: %s", filePath);

        // Read the SRC from the file
        std::string shaderSourceCode = ReadFile(filePath);

        GLenum shaderType = toGlShaderType(type);
        if(shaderType == GL_INVALID_ENUM) {
            g_logger_error("ShaderType is unknown");
            return false;
        }

        // Create an empty shader handle
        shaderId = glCreateShader(shaderType);

        // Send the shader SRC to GL
        const GLchar* sourceCStr = shaderSourceCode.c_str();
        glShaderSource(shaderId, 1, &sourceCStr, nullptr);

        // Compile the shader
        glCompileShader(shaderId);

        // Check if compilation was successful
        GLint isCompiled = 0;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &isCompiled);
        if(!isCompiled) {
            // Compilation failed, let's get the reason and log it to console
            GLint maxLength = 0;
            glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> infoLog(maxLength);
            glGetShaderInfoLog(shaderId, maxLength, &maxLength, &infoLog[0]);

            // Since compilation failed, delete the shader
            glDeleteShader(shaderId);
            g_logger_error("Shader compilation failed: \n%s", infoLog.data());

            shaderId = UINT32_MAX;
            return false;
        }

        return true;
    }

    void Shader::destroy() {
        if(shaderId != UINT32_MAX) {
            glDeleteShader(shaderId);
            shaderId = UINT32_MAX;
        }

        if(filePath != nullptr) {
            g_memory_free(filePath);
            filePath = nullptr;
        }
    }

    void Shader::bind() const {
        glUseProgram(shaderId);
    }

    GLenum Shader::toGlShaderType(ShaderType shader) {
        switch (shader) {
            case ShaderType::Vertex:
                return GL_VERTEX_SHADER;
            case ShaderType::Fragment:
                return GL_FRAGMENT_SHADER;
            default:
                return GL_INVALID_ENUM;
        }
    }

    static std::string ReadFile(const char* filePath) {
        std::string result;
        std::ifstream in(filePath, std::ios::in | std::ios::binary);
        if(in) {
            in.seekg(0, std::ios::end);
            result.resize(in.tellg());
            in.seekg(0, std::ios::beg);
            in.read(&result[0], result.size());
            in.close();
        } else {
            g_logger_error("Could not open file: '%s'", filePath);
        }
        return result;
    }
}