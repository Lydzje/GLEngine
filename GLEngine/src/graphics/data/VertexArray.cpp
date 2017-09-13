#include "VertexArray.h"


VertexArray::VertexArray(const GLfloat *verticesData, GLuint arrayLength, const GLuint nAttribs, 
    const GLuint* attribsNComponents, const GLuint strideInBytes, const GLuint *offsets)
{
    glGenVertexArrays(2, &m_vaoID);
    glGenBuffers(1, &m_vboID[0]);
    glBindVertexArray(m_vaoID);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboID[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*arrayLength, verticesData, GL_STATIC_DRAW);
    
    for (int i = 0; i < nAttribs; i++)
    {
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, attribsNComponents[i], GL_FLOAT, GL_FALSE, strideInBytes, (void*)offsets[i]);

    }
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}


VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_vaoID);
    glDeleteBuffers(1, &m_vboID[0]);
    std::cout << "Deleted VAO!\n";
}


void VertexArray::bind() const
{
    glBindVertexArray(m_vaoID);
}


void VertexArray::unbind() const
{
    glBindVertexArray(0);
}

void VertexArray::bindVBO(unsigned int index)
{
    glBindBuffer(GL_ARRAY_BUFFER, m_vboID[index]);
}

void VertexArray::unbindVBO()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexArray::setBufferData(unsigned int size, glm::mat4* data)
{
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
