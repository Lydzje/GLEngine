#include "Game2D.h"

Game2D::Game2D(unsigned int width, unsigned int height, const char * title)
    : Game(width, height, title),
    m_painter(Painter2D(this))
{
    std::cout << "Game2D created!\n";
}

Game2D::~Game2D()
{
    std::cout << "Game2D destroyed!\n";
}

void Game2D::update() const
{
    Game::update();
    Camera::update();
    m_painter.prepare();
}

void Game2D::render() const
{
    m_painter.clear();
    m_painter.draw();
}
