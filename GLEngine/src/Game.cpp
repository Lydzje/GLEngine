#include "Game.h"

void Game::run()
{
    clock_t timeSinceUpd = clock();
    clock_t deltaTime{ 0 };
    unsigned int frames{ 0 };
    unsigned int updates{ 0 };
    while (!Window::shouldClose())
    {
        clock_t beginFrame = clock();
        if (beginFrame - timeSinceUpd >= m_msPerUpdate)
        {
            timeSinceUpd = clock();
            update();
            ++updates;
        }

        render();
        ++frames;

        Window::update();

        clock_t endFrame = clock();
        deltaTime += endFrame - beginFrame;
        if (deltaTime / CLOCKS_PER_SEC >= 1)
        {
            deltaTime = 0;
            std::cout << frames << " fps | " << updates << " updates\n";
            frames = 0;
            updates = 0;
        }
    }
}

Game::Game(unsigned int width, unsigned int height, const char * title)
    : m_width(width), m_height(height), m_title(title), m_msPerUpdate(16.67f)
{
    init();
    std::cout << "Game created!\n";
}

Game::~Game()
{
    Window::destroy();
    delete m_state;

    std::cout << "Game destroyed!\n";
}

void Game::init()
{
    Window::createWindow(m_width, m_height, m_title);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        std::cout << "Failed to initialize GLAD" << std::endl;

    std::cout << "OpenGL version " << GLVersion.major << "." << GLVersion.minor << "\n\n";

    glfwSwapInterval(0); // No vsync
}

void Game::update() const
{
    m_state->update();
}

