#ifndef SPRITE_SHEET_H
#define SPRITE_SHEET_H

#include "Texture2D.h"

class SpriteSheet
{
public:
    SpriteSheet(const char* path);
    ~SpriteSheet();

    inline const Texture2D& getTexture2D() const { return m_image; }

private:
    Texture2D m_image;

};

#endif // !SPRITE_SHEET_H
