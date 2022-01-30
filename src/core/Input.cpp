#include "Input.h"

namespace MinecraftClone::Input {
    bool keyStatus[GLFW_KEY_LAST] = {};
    bool keyStatusShort[GLFW_KEY_LAST] = {};
    bool mouseButtonStatus[GLFW_MOUSE_BUTTON_LAST] = {};
    float mouseX = 0.0f;
    float mouseY = 0.0f;
    float mouseScrollX = 0.0f;
    float mouseScrollY = 0.0f;
    GLFWgamepadstate state;

    void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if(key >= 0 && key < GLFW_KEY_LAST) keyStatus[key] = action == GLFW_PRESS || action == GLFW_REPEAT;
    }

    void mousePosCallback(GLFWwindow* window, double xpos, double ypos) {
        mouseX = (float) xpos;
        mouseY = (float) ypos;
    }

    void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
        if(button >= 0 && button < GLFW_MOUSE_BUTTON_LAST) mouseButtonStatus[button] = action == GLFW_PRESS;
    }

    void mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
        mouseScrollX = (float) xOffset;
        mouseScrollY = (float) yOffset;
    }

    bool isKeyDown(int key) {
        if(key >= 0 && key < GLFW_KEY_LAST) return keyStatus[key];
        return false;
    }

    bool isMouseDown(int button) {
        if(button >= 0 && button < GLFW_MOUSE_BUTTON_LAST) return mouseButtonStatus[button];
        return false;
    }

    bool isGamepadButtonDown(int button) {
        if(button >= 0 && button < GLFW_GAMEPAD_BUTTON_LAST) {
            if(glfwGetGamepadState(GLFW_JOYSTICK_1, &state)) {
                if(state.buttons[button]) return true;
            }
        }
        return false;
    }

    float getAxisValue(int axis) {
        if(axis >= 0 && axis < GLFW_GAMEPAD_AXIS_LAST) {
            if(glfwGetGamepadState(GLFW_JOYSTICK_1, &state)) {
                return state.axes[axis];
            }
        }
        return 0.0f;
    }
}
