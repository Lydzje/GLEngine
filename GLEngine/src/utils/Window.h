#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW\glfw3.h>
#include <iostream>

#include "Input.h"

class Window
{
public:
    static void createWindow(unsigned int width = 800, unsigned int height = 800, const char *title = "");

    static bool shouldClose();
    static void update();
    static void destroy();

private:
    static GLFWwindow *m_glfwWindow;
    static unsigned int m_width;
    static unsigned int m_height;

private:
    Window() = delete;
    ~Window() = delete;

    static void setCallbacks();

};

#endif // !WINDOW_H

