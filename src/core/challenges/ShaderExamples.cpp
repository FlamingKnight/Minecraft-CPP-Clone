#include <ext/matrix_transform.hpp>
#include <ext/matrix_clip_space.hpp>
#include "ShaderExamples.h"
#include "../rendering/ShaderProgram.h"
#include "../Input.h"

namespace MinecraftClone::ShaderExamples {

    struct Vertex {
        glm::vec3 position;
    };

    static std::array<Vertex, 4> quadVerts = {
            // Position
            Vertex{glm::vec3(-0.5f, -0.5f, 0.0f)}, // Bottom-left
            Vertex{glm::vec3(-0.5f,  0.5f, 0.0f)}, // Top-left
            Vertex{glm::vec3(0.5f,  0.5f, 0.0f)}, // Top-right
            Vertex{glm::vec3(0.5f, -0.5f, 0.0f)}, // Bottom-right
    };

    static std::array<uint32, 6> quadElements = {
            0, 1, 2,   0, 2, 3,
    };

    static uint32 quadVao;
    static uint32 quadVbo;
    static uint32 quadEbo;

    static ShaderProgram shaders;
    static int currentShaderIndex = 0;

    void initQuad() {
        glCreateVertexArrays(1, &quadVao);
        glBindVertexArray(quadVao);

        // Set up and buffer element buffer
        glCreateBuffers(1, &quadEbo);
        glNamedBufferData(quadEbo, sizeof(quadElements), quadElements.data(), GL_STATIC_DRAW);
        glVertexArrayElementBuffer(quadVao, quadEbo);

        // Set up and buffer the vertex buffer
        glCreateBuffers(1, &quadVbo);
        glNamedBufferData(quadVbo, sizeof(quadVerts), quadVerts.data(), GL_STATIC_DRAW);
        glVertexArrayVertexBuffer(quadVao, 0, quadVbo, 0, sizeof(Vertex));

        // Set up and enable attribute 1
        glVertexArrayAttribFormat(quadVao, 0, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, position));
        glVertexArrayAttribBinding(quadVao, 0, 0);
        glEnableVertexArrayAttrib(quadVao, 0);
    }

    void drawQuad(const ShaderProgram& shader, const glm::vec3& position, const glm::vec3& color, float rotation = 0.f, const glm::vec3& scale = glm::vec3(1.f)) {
        glm::mat4 transformMatrix = glm::scale(scale);
        transformMatrix = glm::rotate(transformMatrix, glm::radians(rotation), glm::vec3(0.f, 0.f, 1.f));
        transformMatrix = glm::translate(transformMatrix, position);
        shader.uploadMat4("uTransform", transformMatrix);
        shader.uploadVec2("u_resolution", glm::vec2(1.f));
        glm::vec2 localMouse = glm::vec2(Input::mouseX, Input::mouseY);
        shader.uploadVec2("u_mouse", localMouse);

        glBindVertexArray(quadVao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    }

    void destroyQuad() {
        glDeleteBuffers(1, &quadVbo);
        glDeleteBuffers(1, &quadEbo);
        glDeleteVertexArrays(1, &quadVao);
    }

    glm::mat4 projection;

    void init(const Window& window) {
        shaders.compileAndLink("../assets/shaders/vertex/basic.glsl", "../assets/shaders/fragment/pulsingCircles.glsl");

        initQuad();

        float projectionWidth = 6.f;
        float windowAspect = ((float)window.width/(float)window.height);
        float projectionHeight = projectionWidth/windowAspect;
        projection = glm::ortho(-projectionWidth/2.0f, projectionWidth/2.0f, -projectionHeight/2.0f, projectionHeight/2.0f, 0.001f, 100000.0f);
    }

    void destroy() {
        destroyQuad();
        shaders.destroy();
    }

    void update(float dt) {
        static float keyDebounce = 0.f;
        keyDebounce -= dt;
        shaders.bind();

        static float rotation = 0.f;
        static int lastRotation = -1;
        rotation += dt*50.f;
        float rotationRadians = glm::radians(rotation);
        if((int)(rotation/90) > lastRotation + 1) {
            lastRotation = (int)(rotation/90);
            //TODO: Increase shader index here as if the linear translations are over 90 degrees
        }
        glm::vec3 eye = glm::vec3(20.0f * glm::sin(rotationRadians), 0.0f, 20.0f * glm::cos(rotationRadians)); // Where the camera is
        glm::vec3 center = glm::vec3(0.f, 0.f, 0.f); // Where it's pointing to
        glm::vec3 up = glm::vec3(0.f, 1.f, 0.f); // We need to know which direction points UP for 3D spaces
        glm::mat4 viewMatrix = glm::lookAt(eye, center, up);
        shaders.uploadMat4("uView", viewMatrix);
        shaders.uploadMat4("uProjection", projection);
        shaders.uploadFloat("u_time", (float)glfwGetTime());

        drawQuad(shaders, glm::vec3(0.0f), glm::vec3(1.0f), 0.0f, glm::vec3(3.0f));

        if(Input::isKeyDown(GLFW_KEY_RIGHT && keyDebounce < 0.f)) {
            currentShaderIndex = (currentShaderIndex + 1) % 4;
            keyDebounce = .2f;
        }
    }
}