#ifndef INPUT_H
#define INPUT_H

#include <GLFW\glfw3.h>

class Input
{
public:
    static bool is_mouse_button_pressed(int button);
    static bool is_key_pressed(int key);

private:
    static bool s_keys[1024];
    static bool s_mouseButtons[8];

private:
    Input() = delete;

    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

    friend class Window;
};

#endif // !INPUT_H
