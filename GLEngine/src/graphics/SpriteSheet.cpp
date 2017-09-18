#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(const char* path)
    :m_image(Texture2D(path))
{
}

SpriteSheet::~SpriteSheet()
{
}
