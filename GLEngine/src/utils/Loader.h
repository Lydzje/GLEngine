#ifndef LOADER_H
#define LOADER_H


class Loader
{
public:
    static unsigned int load_shader(const char* vpath, const char* fpath);
    static unsigned int load_texture2D(const char* path);
    static unsigned char* load_image(const char* path, int& width, int& height, bool flip = true);
private:
    Loader() {};
    ~Loader() {};
};

#endif // !LOADER_H



