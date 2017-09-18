#include "Input.h"

bool Input::s_mouseButtons[8]{};
bool Input::s_keys[1024]{};

bool Input::is_key_pressed(int key)
{
    return s_keys[key];
}

bool Input::is_mouse_button_pressed(int button)
{
    return s_mouseButtons[button];
}

void Input:: mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    s_mouseButtons[button] = action == GLFW_PRESS ? true : false;
}

void Input:: key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    s_keys[key] = (action == GLFW_PRESS || action == GLFW_REPEAT) ? true : false;
}
