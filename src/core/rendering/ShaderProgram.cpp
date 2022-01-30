#include <gtc/type_ptr.hpp>
#include "ShaderProgram.h"
#include "Shader.h"

namespace MinecraftClone {

    // Internal Structures
    struct ShaderVariable {
        std::string name;
        GLint varLocation;
        uint32 shaderProgramId;

        bool operator==(const ShaderVariable& other) const {
            return other.shaderProgramId == shaderProgramId && other.name == name;
        }
    };

    struct hashShaderVar {
        std::size_t operator()(const ShaderVariable& key) const {
            std::size_t seed = std::hash<std::string>()(key.name);
            seed ^= std::hash<uint32>()(key.shaderProgramId) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            return seed;
        }
    };

    // Internal Variables
    static auto allShaderVariableLocations = robin_hood::unordered_set<ShaderVariable, hashShaderVar>();

    // Forward Declarations
    static GLint getVariableLocation(const ShaderProgram& shader, const char* varName);

    bool ShaderProgram::compileAndLink(const char *vertexShaderFile, const char *fragmentShaderFile) {
        // Create the shader program
        GLuint program = glCreateProgram();

        Shader vertexShader;
        if(!vertexShader.compile(ShaderType::Vertex, vertexShaderFile)) {
            vertexShader.destroy();
            g_logger_error("Failed to compile a vertex shader");
            return false;
        }

        Shader fragmentShader;
        if(!fragmentShader.compile(ShaderType::Fragment, fragmentShaderFile)) {
            fragmentShader.destroy();
            g_logger_error("Failed to compile a fragment shader");
            return false;
        }

        // Attach the vertex and fragment shaders, try to link them with one another
        glAttachShader(program, vertexShader.shaderId);
        glAttachShader(program, fragmentShader.shaderId);

        // Try to link the program
        glLinkProgram(program);

        // Log errors if we couldn't link
        GLint isLinked = GL_FALSE;
        glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
        if(isLinked == GL_FALSE) {
            GLint maxLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

            // Make sure the max length includes NULL
            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

            // We don't need to keep that memory allocated via the shaders
            glDeleteProgram(program);
            vertexShader.destroy();
            fragmentShader.destroy();

            g_logger_error("Shader Linking Failed:\n%s", infoLog.data());
            programId = UINT32_MAX;
            return false;
        }

        // We need to detach shaders after linking successfully and destroy them since we don't need them anymore?
        glDetachShader(program, vertexShader.shaderId);
        glDetachShader(program, fragmentShader.shaderId);
        vertexShader.destroy();
        fragmentShader.destroy();

        // If linking is ok, get all of the uniforms and store them in a map of uniform variable locations
        int numUniforms;
        glGetProgramiv(program, GL_ACTIVE_UNIFORMS, &numUniforms);

        int maxCharLength;
        glGetProgramiv(program, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxCharLength);
        if(numUniforms > 0 && maxCharLength > 0) {
            char* charBuffer = (char*) g_memory_allocate(sizeof(char) * maxCharLength);

            for(int i = 0; i < numUniforms; i++) {
                int length, size;
                GLenum dataType;
                glGetActiveUniform(program, i, maxCharLength, &length, &size, &dataType, charBuffer);
                GLint varLocation = glGetUniformLocation(program, charBuffer);
                ShaderVariable shaderVar;
                shaderVar.name = std::string(charBuffer, length);
                shaderVar.varLocation = varLocation;
                shaderVar.shaderProgramId = program;
                allShaderVariableLocations.emplace(shaderVar);
            }

            g_memory_free(charBuffer);
        }

        programId = program;
        g_logger_info("Shader compilation and linking succeeded with <Vertex:%s>:<Fragment:%s>", vertexShaderFile, fragmentShaderFile);
        return true;
    }

    void ShaderProgram::destroy() {
        if(programId != UINT32_MAX) {
            glDeleteProgram(programId);
            programId = UINT32_MAX;
        }
    }

    void ShaderProgram::bind() const {
        glUseProgram(programId);
    }

    void ShaderProgram::unbind() const {
        glUseProgram(0);
    }

    void ShaderProgram::uploadVec4(const char *varName, const glm::vec4 &vec4) const {
        int varLocation = getVariableLocation(*this, varName);
        glUniform4f(varLocation, vec4.x, vec4.y, vec4.z, vec4.w);
    }

    void ShaderProgram::uploadVec3(const char *varName, const glm::vec3 &vec3) const {
        int varLocation = getVariableLocation(*this, varName);
        glUniform3f(varLocation, vec3.x, vec3.y, vec3.z);
    }

    void ShaderProgram::uploadVec2(const char *varName, const glm::vec2 &vec2) const {
        int varLocation = getVariableLocation(*this, varName);
        glUniform2f(varLocation, vec2.x, vec2.y);
    }

    void ShaderProgram::uploadIVec4(const char *varName, const glm::ivec4 &vec4) const {
        int varLocation = getVariableLocation(*this, varName);
        glUniform4i(varLocation, vec4.x, vec4.y, vec4.z, vec4.w);
    }

    void ShaderProgram::uploadIVec3(const char *varName, const glm::ivec3 &vec3) const {
        int varLocation = getVariableLocation(*this, varName);
        glUniform3i(varLocation, vec3.x, vec3.y, vec3.z);
    }

    void ShaderProgram::uploadIVec2(const char *varName, const glm::ivec2 &vec2) const {
        int varLocation = getVariableLocation(*this, varName);
        glUniform2i(varLocation, vec2.x, vec2.y);
    }

    void ShaderProgram::uploadFloat(const char *varName, const float value) const {
        int varLocation = getVariableLocation(*this, varName);
        glUniform1f(varLocation, value);
    }

    void ShaderProgram::uploadInt(const char *varName, const int value) const {
        int varLocation = getVariableLocation(*this, varName);
        glUniform1i(varLocation, value);
    }

    void ShaderProgram::uploadIntArray(const char *varName, const int size, const int *array) const {
        int varLocation = getVariableLocation(*this, varName);
        glUniform1iv(varLocation, size, array);
    }

    void ShaderProgram::uploadUInt(const char *varName, const uint32 value) const {
        int varLocation = getVariableLocation(*this, varName);
        glUniform1ui(varLocation, value);
    }

    void ShaderProgram::uploadBool(const char *varName, const bool value) const {
        int varLocation = getVariableLocation(*this, varName);
        glUniform1i(varLocation, value ? 1 : 0);
    }

    void ShaderProgram::uploadMat4(const char *varName, const glm::mat4 &mat4) const {
        int varLocation = getVariableLocation(*this, varName);
        glUniformMatrix4fv(varLocation, 1, GL_FALSE, glm::value_ptr(mat4));
    }

    void ShaderProgram::uploadMat3(const char *varName, const glm::mat3 &mat3) const {
        int varLocation = getVariableLocation(*this, varName);
        glUniformMatrix3fv(varLocation, 1, GL_FALSE, glm::value_ptr(mat3));
    }

    void ShaderProgram::clearAllShaderVariables() {
        allShaderVariableLocations.clear();
    }

    // Private Functions
    static GLint getVariableLocation(const ShaderProgram& shader, const char* varName) {
        ShaderVariable match = {
                varName,
                0,
                shader.programId
        };
        auto iter = allShaderVariableLocations.find(match);
        if (iter != allShaderVariableLocations.end()) {
            return iter->varLocation;
        }

        return -1;
    }


}