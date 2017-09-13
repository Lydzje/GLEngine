#ifndef INPUT_H
#define INPUT_H

#include <GLFW\glfw3.h>

class Input
{
public:
    static bool isMouseButtonPressed(int button);
    static bool isKeyPressed(int key);


private:
    static bool keys[1024];
    static bool mouseButtons[8];

private:
    Input() = delete;

    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

    friend class Window;
};

#endif // !INPUT_H



