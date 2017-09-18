#include "Painter2D.h"

#include <iostream>
#include <glad\glad.h>
#include <glm\gtc\matrix_transform.hpp>

#include "../entities/Entity.h"
#include "../utils/Camera.h"

Painter2D::Painter2D(Game* canvas)
    : Painter(canvas)
{
    init();
    std::cout << "Painted2D created!\n";
}

Painter2D::~Painter2D()
{
    delete m_vao;
    delete m_shader;
    std::cout << "Painted2D destroyed!\n";
}

void Painter2D::prepare() const
{
    m_shader->setMat4("view", Camera::get_view_matrix());
}

void Painter2D::draw() const
{
    unsigned int lastTexture{ 0 };
    for (Entity* e : Entity::s_entities)
    {
        if (lastTexture != e->getTexture2DID())
        {
            lastTexture = e->getTexture2DID();
            m_shader->setTexture2D("tex", 0);
        }
        m_shader->setMat4("model", e->getModelMatrix());
        glDrawArrays(GL_TRIANGLES, 0, 6);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
}

bool Painter2D::init()
{
    float verticesData[]
    {
        // Positions and tex coords
         0.5f,  0.5f, 1, 1,
         0.5f, -0.5f, 1, 0,
        -0.5f, -0.5f, 0, 0,

        -0.5f, -0.5f, 0, 0,
        -0.5f,  0.5f, 0, 1,
         0.5f,  0.5f, 1, 1

        /* Only 4 vertices needed for glDrawElements()
        -0.5f,  0.5f, 0, 1,
         0.5f,  0.5f, 1, 1,
         0.5f, -0.5f, 1, 0,
        -0.5f, -0.5f, 0, 0,*/

    };

    unsigned int indices[] =
    {
        0, 1, 2,
        0, 3, 2
    };

    unsigned int attribsNComponents[]{ 2, 2 };
    unsigned int offsets[]{ 0, sizeof(float)*2 };
    m_vao = new VertexArray{ verticesData, 24, 2, attribsNComponents, sizeof(float)*4, offsets, indices, 6 };
    m_shader = new Shader("res\\shaders\\2d.vert", "res\\shaders\\2d.frag");

    m_vao->bind();
    m_shader->use();

    glm::mat4 perspective = glm::perspective(glm::radians(45.0f), m_canvas->getRatio(), 0.0f, 100.0f);
    m_shader->setMat4("projection", glm::value_ptr(perspective));

    return true;
}
