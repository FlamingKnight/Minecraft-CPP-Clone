#ifndef MINECRAFTCLONE_INPUT_H
#define MINECRAFTCLONE_INPUT_H

#include "../core.h"

namespace MinecraftClone::Input {
    extern bool keyStatus[GLFW_KEY_LAST];
    extern bool mouseButtonStatus[GLFW_MOUSE_BUTTON_LAST];
    extern float mouseX;
    extern float mouseY;
    extern float mouseScrollX;
    extern float mouseScrollY;
    extern GLFWgamepadstate state;

    void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void mousePosCallback(GLFWwindow* window, double xpos, double ypos);
    void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    void mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset);

    bool isKeyDown(int key);
    bool isMouseDown(int button);
    bool isGamepadButtonDown(int button);
    float getAxisValue(int axis);
}


#endif //MINECRAFTCLONE_INPUT_H
