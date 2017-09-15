#include "Sprite.h"

#include <iostream>


Sprite::Sprite(int x, int y, SpriteSheet& sheet)
    : m_x(x), m_y(y), m_sheet(sheet)
{
    std::cout << "Sprite created!\n";
}


Sprite::~Sprite()
{
    std::cout << "Sprite destroyed!\n";
}
