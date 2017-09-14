#ifndef VAO_H
#define VAO_H

#include <glad\glad.h>
#include <iostream>

#include <glm\glm.hpp>

class VertexArray
{
public:
    VertexArray(const GLfloat *verticesData, GLuint verticesLength, const GLuint nAttribs, 
        const GLuint* attribsNComponents, const GLuint stride, const GLuint *offsets,
        const GLuint *indices, const GLuint indicesLength);
    ~VertexArray();

    void bind() const;
    void unbind() const;

    void bindVBO(unsigned int index);
    void unbindVBO();
    void setBufferData(unsigned int size, glm::mat4* data);

private:
    GLuint m_vaoID;
    GLuint m_vboID[2];
    GLuint m_eboID;
};

#endif // !VAO_H



