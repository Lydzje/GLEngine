#include "Shader.h"

#include <iostream>


Shader::Shader(const char * vpath, const char * fpath)
    : m_id(Loader::load_shader(vpath, fpath))
{
}

Shader::~Shader()
{
    std::cout << "Shader deleted!\n";
}

void Shader::use() const
{
    glUseProgram(m_id);
}

void Shader::setVec2(const char *name, const float *vec2) const
{
    glUniform2fv(glGetUniformLocation(m_id, name), 1, vec2);
}

void Shader::setVec4(const char *name, const float *vec4) const
{
    glUniform4fv(glGetUniformLocation(m_id, name), 1, vec4);
}

void Shader::setMat4(const char *name, const float *mat4) const
{    
    glUniformMatrix4fv(glGetUniformLocation(m_id, name), 1, GL_FALSE, mat4);
}

void Shader::setTexture2D(const char *name, const int unit) const
{
    glUniform1i(glGetUniformLocation(m_id, name), unit);
}

