#ifndef SPRITE_SHEET_H
#define SPRITE_SHEET_H

#include "Texture2D.h"

class SpriteSheet
{
public:
    SpriteSheet(const char* path);
    ~SpriteSheet();

    inline Texture2D& getTexture2D() { return image; }

private:
    Texture2D image;

};

#endif // !SPRITE_SHEET_H



