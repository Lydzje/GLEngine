#include "Texture2D.h"

#include <glad\glad.h>
#include <iostream>
#include "../utils/Loader.h"

Texture2D::Texture2D(const char* path)
    : m_id(Loader::load_texture2D(path))
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_id);
}

Texture2D::~Texture2D()
{
    std::cout << "Texture2D deleted!\n";
}
