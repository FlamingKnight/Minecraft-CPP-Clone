#include <cstring>
#include "Window.h"
#include "Input.h"
#include "utilities/Utilities.h"
#include "utilities/Logger.h"

namespace MinecraftClone {

    static void resizeCallback(GLFWwindow* nativeWindow, int newWidth, int newHeight) {
        auto* window = (Window*)glfwGetWindowUserPointer(nativeWindow);
        window->width = newWidth;
        window->height = newHeight;
        glViewport(0, 0, newWidth, newHeight);
    }

    void Window::installMainCallbacks() const {
        if(nativeWindow != nullptr) {
            glfwSetKeyCallback(nativeWindow, Input::keyCallback);
            glfwSetCursorPosCallback(nativeWindow, Input::mousePosCallback);
            glfwSetMouseButtonCallback(nativeWindow, Input::mouseButtonCallback);
            glfwSetWindowSizeCallback(nativeWindow, resizeCallback);
        }
    }

    void Window::close() const {
        if(nativeWindow != nullptr) glfwSetWindowShouldClose(nativeWindow, GLFW_TRUE);
    }

    Window* Window::createWindow(int width, int height, const char *title, bool fullscreen) {
        //Choose version 4.6 for GLAD
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        //Core profile says we are not going to be using deprecated features
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        //glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

        auto* window = new Window();
        GLFWmonitor* primaryMonitor = fullscreen ? glfwGetPrimaryMonitor() : nullptr;
        window->nativeWindow = glfwCreateWindow(width, height, title, primaryMonitor, nullptr);
        if(window->nativeWindow == nullptr)
            MinecraftClone::Utilities::closeSafely("GLFW Window could not be created\n");
        glfwMakeContextCurrent(window->nativeWindow);
        glfwSetWindowUserPointer(window->nativeWindow, (void*) window);

        window->width = width;
        window->height = height;

        return window;
    }

    void Window::freeWindow(Window *window) {
        if(window) {
            glfwDestroyWindow(window->nativeWindow);
            delete window;
        }
    }

    void Window::GLErrorCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
                                 const GLchar *message, const void *userParam) {
        switch (severity) {
            case GL_DEBUG_SEVERITY_HIGH:
                Logger::error(std::strcat((char *) &"OpenGL HIGH: ", message));
                break;
            case GL_DEBUG_SEVERITY_MEDIUM:
                Logger::info(std::strcat((char *) &"OpenGL Medium: ", message));
                break;
            case GL_DEBUG_SEVERITY_LOW:
                Logger::info(std::strcat((char *) &"OpenGL Low: ", message));
                break;
            case GL_DEBUG_SEVERITY_NOTIFICATION:
                Logger::info(std::strcat((char *) &"OpenGL Notification: ", message));
                break;
            default: break;
        }
    }
};
