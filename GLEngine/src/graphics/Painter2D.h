#ifndef PAINTER2D_H
#define PAINTER2D_H

#include "Painter.h"
#include "data\VertexArray.h"
#include "Shader.h"

class Painter2D : public Painter
{
public:
    Painter2D(Game* canvas);
    ~Painter2D();

    void prepare() const override;
    void draw() const override;

private:
    VertexArray* m_vao;
    Shader* m_shader;

private:
    bool init() override;

};

#endif // !PAINTER2D_H
