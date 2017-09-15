#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW\glfw3.h>


class Window
{
public:
    static void createWindow(unsigned int width = 800, unsigned int height = 800, const char *title = "");

    static void set_icon(const char* path);
    static bool shouldClose();// needs static method convenction
    static void update();
    static void destroy();


private:
    static GLFWwindow *m_glfwWindow;
    static unsigned int m_width;
    static unsigned int m_height;

private:
    Window() = delete;
    ~Window() = delete;

    static void set_callbacks();
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

};

#endif // !WINDOW_H

