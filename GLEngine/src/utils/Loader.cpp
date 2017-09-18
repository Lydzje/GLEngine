#include "Loader.h"

#include <glad\glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "stb_image.h"

unsigned int Loader::load_shader(const char* vpath, const char* fpath)
{
    // Getting the shader source code from files
    // -----------------------------------------
    std::ifstream vShaderFile, fShaderFile;
    std::string vShaderString, fShaderString;

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        vShaderFile.open(vpath);
        std::cout << "Reading " << vpath << " succeded!\n";
        fShaderFile.open(fpath);
        std::cout << "Reading " << fpath << " succeded!\n";
        std::stringstream vShaderStream, fShaderStream;
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        vShaderFile.close();
        fShaderFile.close();
        vShaderString = std::move(vShaderStream.str());
        fShaderString = std::move(fShaderStream.str());

    } catch (std::ifstream::failure)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }

    const char* vShaderCode{ vShaderString.c_str() };
    const char* fShaderCode{ fShaderString.c_str() };

    // Compiling shaders
    // -----------------
    int success;
    char infoLog[512];
    // vertex shader
    GLuint vertexID{ glCreateShader(GL_VERTEX_SHADER) };
    glShaderSource(vertexID, 1, &vShaderCode, nullptr);
    glCompileShader(vertexID);
    glGetShaderiv(vertexID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };
    // fragment shader
    GLuint fragmentID{ glCreateShader(GL_FRAGMENT_SHADER) };
    glShaderSource(fragmentID, 1, &fShaderCode, nullptr);
    glCompileShader(fragmentID);
    glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    };
    // program shader
    GLuint programID{ glCreateProgram() };
    glAttachShader(programID, vertexID);
    glAttachShader(programID, fragmentID);
    glLinkProgram(programID);
    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(programID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    // Deleting shaders
    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);

    return programID;
}

unsigned int Loader::load_texture2D(const char* path)
{
    int width, height;
    unsigned char* data = load_image(path, width, height);

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);

    return textureID;
}

unsigned char* Loader::load_image(const char* path, int& width, int& height, bool flip)
{
    stbi_set_flip_vertically_on_load(flip);

    int nChannels;
    unsigned char* data = stbi_load(path, &width, &height, &nChannels, 0);
    std::cout << "Loading " << path;
    if (!data)
        std::cout << " FAILED!\n";
    else
        std::cout << " SUCCEDED!\n";

    return data;
}
