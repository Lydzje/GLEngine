#include "Window.h"

GLFWwindow *Window::m_glfwWindow{ nullptr };
unsigned int Window::m_width;
unsigned int Window::m_height;

void Window::createWindow(unsigned int width, unsigned int height, const char * title)
{
    if (!glfwInit())
        std::cout << "Failed to initialize GLFW" << std::endl;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_width = width;
    m_height = height;
    m_glfwWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (!m_glfwWindow)
        std::cout << "Failed to create GLFW window" << std::endl;

    glfwMakeContextCurrent(m_glfwWindow);

    setCallbacks();

    std::cout << "Window created!\n";
}

bool Window::shouldClose()
{
    return glfwWindowShouldClose(m_glfwWindow);
}

void Window::update()
{
    glfwSwapBuffers(m_glfwWindow);
    glfwPollEvents();
}

void Window::destroy()
{
    glfwTerminate();
    std::cout << "Window destroyed!\n";
}

void Window::setCallbacks()
{
    glfwSetMouseButtonCallback(m_glfwWindow, Input::mouse_button_callback);
    glfwSetKeyCallback(m_glfwWindow, Input::key_callback);
}
