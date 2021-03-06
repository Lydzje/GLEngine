#ifndef SHADER_H
#define SHADER_H

class Shader
{
public:
    Shader(const char * vpath, const char * fpath);
    ~Shader();

    void use() const;

    void setVec2(const char* name, const float* vec2) const;
    void setVec4(const char* name, const float* vec4) const;
    void setMat4(const char* name, const float* mat4) const;
    void setTexture2D(const char* name, const int unit) const;

private:
    unsigned int m_id;

};

#endif // !SHADER_H
