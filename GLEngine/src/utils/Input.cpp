#include "Input.h"

bool Input::mouseButtons[8]{};
bool Input::keys[1024]{};

bool Input::isKeyPressed(int key)
{
    return keys[key];
}

bool Input::isMouseButtonPressed(int button)
{
    return mouseButtons[button];
}

void Input:: mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    mouseButtons[button] = action == GLFW_PRESS ? true : false;
}

void Input:: key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    keys[key] = (action == GLFW_PRESS || action == GLFW_REPEAT) ? true : false;
}