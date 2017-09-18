#include "GameExample1.h"

#include <iostream>

#include "../src/gameplay/examples/TestScene.h"

GameExample1::GameExample1(unsigned int width, unsigned int height, const char * title)
    : Game2D(width, height, title)
{
    m_state = new TestScene();
    std::cout << "GameExample created!\n";
}

GameExample1::~GameExample1()
{
    std::cout << "GameExample destroyed!\n";
}
