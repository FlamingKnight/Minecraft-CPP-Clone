
#ifndef MINECRAFTCLONE_SHADERPROGRAM_H
#define MINECRAFTCLONE_SHADERPROGRAM_H

#include "../../core.h"

namespace MinecraftClone {
    struct ShaderProgram {
        uint32 programId;

        bool compileAndLink(const char* vertexShaderFile, const char* fragmentShaderFile);
        void bind() const;
        void unbind() const;
        void destroy();

        void uploadVec4(const char* varName, const glm::vec4& vec4) const;
        void uploadVec3(const char* varName, const glm::vec3& vec3) const;
        void uploadVec2(const char* varName, const glm::vec2& vec2) const;
        void uploadIVec4(const char* varName, const glm::ivec4& vec4) const;
        void uploadIVec3(const char* varName, const glm::ivec3& vec3) const;
        void uploadIVec2(const char* varName, const glm::ivec2& vec2) const;

        void uploadFloat(const char* varName, const float value) const;
        void uploadInt(const char* varName, const int value) const;
        void uploadIntArray(const char* varName, const int size, const int* array) const;
        void uploadUInt(const char* varName, const uint32 value) const;
        void uploadBool(const char* varName, const bool value) const;

        void uploadMat4(const char* varName, const glm::mat4& mat4) const;
        void uploadMat3(const char* varName, const glm::mat3& mat3) const;

        static void clearAllShaderVariables();
    };
}


#endif //MINECRAFTCLONE_SHADERPROGRAM_H
