#include "Painter.h"

#include <iostream>
#include <glad\glad.h>

void Painter::clear() const
{
    glClearColor(0.15f, 0.24f, 0.41f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

Painter::Painter(Game* canvas)
    :m_canvas(canvas)
{
}

Painter::~Painter()
{
}
