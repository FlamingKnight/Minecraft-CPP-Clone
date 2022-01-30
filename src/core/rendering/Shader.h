//
// Created by asher on 12/24/2021.
//

#ifndef MINECRAFTCLONE_SHADER_H
#define MINECRAFTCLONE_SHADER_H

#include "../../core.h"

namespace MinecraftClone {

    enum class ShaderType : uint8 {
        Vertex,
        Fragment,
    };

    struct Shader {
        char* filePath;
        uint32 shaderId;
        ShaderType shaderType;
        void bind() const;
        bool compile(ShaderType type, const char* shaderFilePath);
        void destroy();

        static GLenum toGlShaderType(ShaderType shader);
    };

    static std::string ReadFile(const char* filePath);
}

#endif //MINECRAFTCLONE_SHADER_H
