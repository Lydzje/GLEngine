#include "SpriteSheet.h"



SpriteSheet::SpriteSheet(const char* path)
    :image(Texture2D(path))
{
}


SpriteSheet::~SpriteSheet()
{
}
