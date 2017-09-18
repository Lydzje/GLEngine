#include "VertexArray.h"

#include <iostream>
#include <glad\glad.h>

VertexArray::VertexArray(const float *verticesData, unsigned int verticesLength,
    const unsigned int nAttribs, const unsigned int* attribsNComponents,
    const unsigned int strideInBytes, const unsigned int *offsets,
    const unsigned int *indices, const unsigned int indicesLength)
{
    glGenVertexArrays(2, &m_vaoID);
    glGenBuffers(1, &m_vboID[0]);
    //glGenBuffers(1, &m_eboID);
    glBindVertexArray(m_vaoID);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboID[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*verticesLength, verticesData, GL_STATIC_DRAW);
    
    for (int i = 0; i < nAttribs; i++)
    {
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, attribsNComponents[i], GL_FLOAT, GL_FALSE, strideInBytes, (void*)offsets[i]);

    }
    
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_eboID);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*indicesLength, indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_vaoID);
    glDeleteBuffers(1, &m_vboID[0]);
    //glDeleteBuffers(1, &m_eboID);
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
