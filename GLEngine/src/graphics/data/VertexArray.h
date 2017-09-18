#ifndef VAO_H
#define VAO_H

#include <glm\glm.hpp>

class VertexArray
{
public:
    VertexArray(const float *verticesData, unsigned int verticesLength, 
        const unsigned int nAttribs, const unsigned int* attribsNComponents, 
        const unsigned int strideInBytes, const unsigned int *offsets,
        const unsigned int *indices, const unsigned int indicesLength);

    ~VertexArray();

    void bind() const;
    void unbind() const;

    void bindVBO(unsigned int index);
    void unbindVBO();
    void setBufferData(unsigned int size, glm::mat4* data);

private:
    unsigned int m_vaoID;
    unsigned int m_vboID[2];
    unsigned int m_eboID;
};

#endif // !VAO_H
