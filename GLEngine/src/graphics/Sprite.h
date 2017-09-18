#ifndef SPRITE_H
#define SPRITE_H

#include "SpriteSheet.h"

class Sprite
{
public:
    Sprite(int x, int y, SpriteSheet& sheet);
    ~Sprite();

    inline SpriteSheet& getSpriteSheet() const { return m_sheet; }

private:
    SpriteSheet& m_sheet;
    int m_x;
    int m_y;
};

#endif // !SPRITE_H
