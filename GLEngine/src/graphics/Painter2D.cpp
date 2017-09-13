#include "Painter2D.h"


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
    m_shader->setMat4("view", Camera::getViewMatrix());
}

void Painter2D::draw() const
{
    unsigned int lastTexture{ 0 };
    for (Entity* e : Entity::entities)
    {
        if (lastTexture != e->getTexture2DID())
        {
            lastTexture = e->getTexture2DID();
            m_shader->setTexture2D("tex", 0);
        }
        m_shader->setMat4("model", e->getModelMatrix());
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }
}

bool Painter2D::init()
{
    GLfloat verticesData[]
    {
        // Positions and tex coords
         0.5f,  0.5f, 1, 1,
         0.5f, -0.5f, 1, 0,
        -0.5f, -0.5f, 0, 0,

        -0.5f, -0.5f, 0, 0,
        -0.5f,  0.5f, 0, 1,
         0.5f,  0.5f, 1, 1
    };

    GLuint attribsNComponents[]{ 2, 2 };
    GLuint offsets[]{ 0, sizeof(GLfloat)*2 };
    m_vao = new VertexArray{ verticesData, 24, 2, attribsNComponents, sizeof(GLfloat)*4, offsets };
    m_shader = new Shader("res\\shaders\\2d.vert", "res\\shaders\\2d.frag");

    m_vao->bind();
    m_shader->use();

    glm::mat4 perspective = glm::perspective(glm::radians(45.0f), m_canvas->getRatio(), 0.0f, 100.0f);
    m_shader->setMat4("projection", glm::value_ptr(perspective));

    return true;
}
