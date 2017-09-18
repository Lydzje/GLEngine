#ifndef PAINTER_H
#define PAINTER_H

#include "../Game.h"

class Painter
{
public:
    virtual void prepare() const = 0;
    virtual void draw() const = 0;
    virtual void clear() const;

protected:
    Game* m_canvas;

protected:
    Painter(Game* canvas);
    virtual ~Painter();

    virtual bool init() = 0;

};

#endif // !PAINTER_H
