#ifndef DRAWABLE_2D_H
#define DRAWABLE_2D_H

#include "../graphics/Sprite.h"

class Drawable2D
{
public:
    ~Drawable2D() {};

    unsigned int getTexture2DID() const;

protected:
    Drawable2D(Sprite* sprite);

private:
    Sprite* m_sprite;

};

#endif // !DRAWABLE_2D_H
