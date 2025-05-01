#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <stb/stb-image.h>
#include "shader.h"

class Texture {
    public:
        GLuint ID;
        GLenum type;
        Texture();
        Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType, GLenum internalFormat, bool shouldFlip);

        void texUnit(Shader& shader, const char* uniform, GLuint unit);
        void Bind();
        void Unbind();
        void Delete();
};

#endif