#ifndef VAO_H
#define VAO_H

#include "vbo.h"

class VAO {
    public:
        GLuint ID;
        VAO();

        void LinkAttribute(VBO vbo, GLuint layout, GLint size, GLenum type, GLsizei stride, const void* offset);
        void Bind() const;
        void Unbind() const;
        void Clean() const;
};

#endif