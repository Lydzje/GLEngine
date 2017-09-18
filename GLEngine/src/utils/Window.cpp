#include "Window.h"

#include <iostream>

#include "Loader.h"
#include "Input.h"

GLFWwindow *Window::m_glfwWindow{ nullptr };
unsigned int Window::m_width;
unsigned int Window::m_height;

void Window::createWindow(unsigned int width, unsigned int height, const char* title)
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

    set_callbacks();
    set_icon("res\\images\\icon.png");

    std::cout << "Window created!\n";
}

void Window::set_icon(const char* path)
{
    GLFWimage icons[1];
    icons[0].pixels = Loader::load_image(path, icons[0].width, icons[0].height, false);
    glfwSetWindowIcon(m_glfwWindow, 1, icons);
}

bool Window::should_close()
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

void Window::set_callbacks()
{
    glfwSetFramebufferSizeCallback(m_glfwWindow, framebuffer_size_callback);
    glfwSetMouseButtonCallback(m_glfwWindow, Input::mouse_button_callback);
    glfwSetKeyCallback(m_glfwWindow, Input::key_callback);
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    std::cout << "WINDOW RESIZED\n";
    m_width = width;
    m_height = height;
    glViewport(0, 0, m_width, m_height);
}
