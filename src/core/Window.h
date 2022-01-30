#ifndef MINECRAFTCLONE_WINDOW_H
#define MINECRAFTCLONE_WINDOW_H
#include "../core.h"

namespace MinecraftClone {
    struct Window {
        GLFWwindow* nativeWindow;
        int width;
        int height;

        /**
         * Initializes all of the necessary callbacks related to events
         */
        void installMainCallbacks() const;

        /**
         * Closes the window for GLFW, telling it to exit out of the main loop (glfwSetWindowShouldClose)
         */
        void close() const;

        static void GLErrorCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

        /**
         * A large function which initializes and sets up a GLFW window and sets its hints
         * @param width
         * @param height
         * @param title
         * @param fullscreen If true, primaryMonitor from GLFW will be used
         * @return this
         */
        static Window* createWindow(int width, int height, const char* title, bool fullscreen = false);

        /**
         * Uses GLFW to destroy the window being viewed, then the pointer is deleted
         * @param window
         */
        static void freeWindow(Window* window);
    };
}

#endif //MINECRAFTCLONE_WINDOW_H
