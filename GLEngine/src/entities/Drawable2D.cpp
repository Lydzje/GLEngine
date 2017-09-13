#include "Drawable2D.h"

unsigned int Drawable2D::getTexture2DID()
{
    return m_sprite->getSpriteSheet().getTexture2D().getID();
}

Drawable2D::Drawable2D(Sprite* sprite)
    :m_sprite(sprite)
{
}
