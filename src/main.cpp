/**
 *  Topic List:
 * 1. Window management and Game loop - Done
 * 2. Buffers, Vertices, and OpenGL Objects - Done (Merged challenges 2 and 4)
 * 3. GLSL Shaders
 * 4. Texture packing and dynamic UVs
 * 5. 3D Player controllers and cameras
 * 6. Cubes, chunks, and subchunks
 * 7. Basic procedural generation
 * 8. Multithreading
 * 9. Chunk loading/unloading
 * 10. OpenGL AZDO
 * 11. Minecraft like lighting
 * 12. Order independent transparency
 * 13. Entity component system (ECS)
 * 14. Basic physics
 * 15. Font rendering
 * 16. GUIs and HUDs
 * 17. Scene management
 * 18. Framebuffers
 * 19. Command line parsing
 * 20. Cubemaps
 * 21. Inventory management
 * 22. Crafting
 * 23. Multiplayer
 * 24. Deferred rendering
 * 25. Raytracing
 */
#include <iostream>
#include <windows.h>
#include <ext/matrix_transform.inl>
#include <ext/matrix_clip_space.hpp>
#include "core.h"
#include "core/Input.h"
#include "core/Window.h"
#include "core/utilities/Utilities.h"
#include "core/utilities/Logger.h"
#include "core/rendering/Shader.h"
#include "core/utilities/Timer.h"
#include "core/rendering/ShaderProgram.h"
#include "core/challenges/ShaderExamples.h"

using namespace MinecraftClone;

const short windowWidth = 1280;
const short windowHeight = 720;
const char* title = "Minecraft Clone";

/*static uint32 vaoId;
static uint32 vboId;
static uint32 eboId;
static uint32 vertexBindingPoint = 0;
static uint32 colorAttributeSlot = 0;
static uint32 positionAttributeSlot = 1;
void setupVertex(Vertex* vbo, uint32* ebo, uint32 vboSize, uint32 eboSize) {
    //Setup and bind VAO
    glCreateVertexArrays(1, &vaoId);
    glBindVertexArray(vaoId);

    //Setup and buffer EBO
    glCreateBuffers(1, &eboId);
    glNamedBufferData(eboId, eboSize, ebo, GL_STATIC_DRAW);
    glVertexArrayElementBuffer(vaoId, eboId);

    //Setup and buffer the VBO
    glCreateBuffers(1, &vboId);
    glNamedBufferData(vboId, vboSize, vbo, GL_STATIC_DRAW);
    //The second parameter, multiple buffers for different attributes, so we use 0 for the Vertex object with its shader?
    glVertexArrayVertexBuffer(vaoId, vertexBindingPoint, vboId, 0, sizeof(Vertex));

    //Sets up the formatting for the colorAttributeSlot
    glVertexArrayAttribFormat(vaoId, colorAttributeSlot, 4, GL_FLOAT, GL_FALSE, offsetof(Vertex, color));
    //Binds the buffer slot with colorAttributeSlot
    glVertexArrayAttribBinding(vaoId, colorAttributeSlot, vertexBindingPoint);
    //Finalizes the stuff
    glEnableVertexArrayAttrib(vaoId, colorAttributeSlot);

    glVertexArrayAttribFormat(vaoId, positionAttributeSlot, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, position));
    glVertexArrayAttribBinding(vaoId, positionAttributeSlot, vertexBindingPoint);
    glEnableVertexArrayAttrib(vaoId, positionAttributeSlot);
}*//*


*/
/**
 * ==================================================
 * EPISODE 2
 * ==================================================
*//*

*/
/*void transformationMatrix() {
    /// NOTE: The following NEEDS to be done in order, as scale, rotation, and finally translation
    // How much to scale the object in XYZ
    glm::mat4 transform = glm::scale(glm::vec3(1,1,1) *//*
*/
/*Scale*//*
*/
/*);
    // We're rotating the object around 1 radian around the Z axis
    transform = glm::rotate(transform, glm::radians(1.f), glm::vec3(0.f, 0.f, 1.f));
    //Finally we move the object to its position
    transform = glm::translate(transform, glm::vec3(1,1,1) *//*
*/
/*Position*//*
*/
/*);

    /// Now we need a view matrix
    /// The view matrix is mainly stuff related to the camera: it can determine game world location
    /// The following has our camera at 0,0,20 and looking towards 0,0,0
    glm::vec3 eye = glm::vec3(0.f, 0.f, 20.f); // Where the camera is
    glm::vec3 center = glm::vec3(0.f, 0.f, 0.f); // Where it's pointing to
    glm::vec3 up = glm::vec3(0.f, 1.f, 0.f); // We need to know which direction points UP for 3D spaces
    glm::mat4 viewMatrix = glm::lookAt(eye, center, up);

    /// Finally we need a projection matrix
    /// This one will be important for defining our world units
    /// The following is for a 2D game:
    *//*
*/
/*    float projectionWidth = windowWidth;
        float windowAspect = ((float) windowWidth / (float) windowHeight);
        float projectionHeight = projectionWidth / windowAspect; // Can just be 1080.f, same as windowHeight

        float left = -projectionWidth / 2.f;
        float right = projectionWidth / 2.f;
        float bottom = -projectionHeight / 2.f;
        float top = projectionHeight / 2.f;
        float nearP = 0.0001f;
        float farP = 10000.f;

        glm::mat4 projectionMatrix = glm::ortho(left, right, bottom, top, nearP, farP);*//*
*/
/*
    /// If only we could upload images, extremely useful visual at episode 3 6:28

    /// Now for a 3D game projection matrix
    float fov = 45.f;
    float nearP = 0.01f;
    float farP = 10000.f;
    float windowAspect = ((float) windowWidth)/((float) windowHeight);
    glm::mat4 projection = glm::perspective(fov, windowAspect, nearP, farP);

    /// Now to send to GPU:
    /// This will upload the matrix to the location specified as the first parameter,
    /// the following will be uploaded to the uTransform in the shader
    glUniformMatrix4fv(0, 1, GL_FALSE, glm::value_ptr(transform));
}*/


void GLAPIENTRY errorMessageCallback(
        GLenum source,
        GLenum type,
        GLuint id,
        GLenum severity,
        GLsizei length,
        const GLchar* message,
        const void* userParam) {
    g_logger_error("GL CALLBACK: **GL ERROR** type = 0x%x, severity = 0x%x, message = %s\n",
                   type, severity, message);
}

void glfwErrorCallback(int error, const char* description) {
    g_logger_error("GLFW CALLBACK: **GLFW ERROR** Error: %d description: %s\n", error, description);
}


int main() {
    /// For debugging, apparently this needs to be run to use console at least once
    setbuf(stdout, nullptr);

    // Start up some utility classes
    Logger::level = Logger::Level::ALL;

#ifndef DEBUG
    Logger::log("Debug is not set in this build");
#endif

    // Initialize GLFW
    glfwSetErrorCallback(glfwErrorCallback);
    if(!glfwInit())
        return Utilities::closeSafely("Failed to initialize GLFW\n");


    // Create window to start game and register callbacks using the window object
    Window* window = Window::createWindow(windowWidth, windowHeight, title, false);
    if(window == nullptr)
        return Utilities::closeSafely("Failed to initialize window\n");
    window->installMainCallbacks();


    // Initialize GLAD
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        return Utilities::closeSafely("Failed to initialize GLAD\n");
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(errorMessageCallback, nullptr);
    glEnable(GL_DEPTH_TEST);
    // Set up shaders
    glViewport(0, 0, windowWidth, windowHeight); //View from here to here and draw
    float dt = 0.016f;
    float frameStart = 0.f;
    ShaderExamples::init(*window);
    float keyDebounce = .1f;


    while(!glfwWindowShouldClose(window->nativeWindow)) {
        dt = glfwGetTime() - frameStart;
        frameStart = glfwGetTime();

        glClearColor(39.0f/255.0f, 40.0f/255.0f, 34.0f/255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        keyDebounce -= dt;

        ShaderExamples::update(dt);

        glfwSwapBuffers(window->nativeWindow);
        glfwPollEvents();
    }

    ShaderExamples::destroy();

    Window::freeWindow(window);
    glfwTerminate();

    return 0;
}