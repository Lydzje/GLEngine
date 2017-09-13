#ifndef LOADER_H
#define LOADER_H

#include <glad\glad.h>
#include "stb_image.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Loader
{
public:
    static GLuint loadShader(const char* vpath, const char* fpath);
    static GLuint loadTexture2D(const char* path, int& width, int& height);
private:
    Loader() {};
    ~Loader() {};
};

#endif // !LOADER_H



