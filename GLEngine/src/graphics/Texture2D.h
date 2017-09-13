#ifndef TEXTURE_2D_H
#define TEXTURE_2D_H

#include "../utils/Loader.h"

class Texture2D
{
public:
    Texture2D(const char* path);
    ~Texture2D();

    inline unsigned int getID() { return m_id; }

private:
    GLuint m_id;
    int m_width;
    int m_height;
};

#endif // !TEXTURE_2D_H




