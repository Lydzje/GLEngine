#include "Texture2D.h"



Texture2D::Texture2D(const char* path)
    : m_id(Loader::loadTexture2D(path, m_width, m_height))
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_id);
}

Texture2D::~Texture2D()
{
    std::cout << "Texture2D deleted!\n";
}
