#ifndef TEXTURE_2D_H
#define TEXTURE_2D_H

class Texture2D
{
public:
    Texture2D(const char* path);
    ~Texture2D();

    inline unsigned int getID() const { return m_id; }

private:
    unsigned int m_id;
};

#endif // !TEXTURE_2D_H
