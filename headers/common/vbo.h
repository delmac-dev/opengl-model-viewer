#ifndef VBO_H
#define VBO_H

#include <glad/glad.h>

class VBO {
    public:
        GLuint ID;
        VBO() = default;
        VBO(GLfloat* vertices, GLsizeiptr size);

        void Bind() const;
        void Unbind() const;
        void Clean() const;
};

#endif