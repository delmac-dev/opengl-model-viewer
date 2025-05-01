#include "common/vao.h"

VAO::VAO() {
    glGenVertexArrays(1, &ID);
}

void VAO::LinkAttribute(VBO vbo, GLuint layout, GLint size, GLenum type, GLsizei stride, const void* offset) {
    Bind();
    vbo.Bind();
    glVertexAttribPointer(layout, size, type, GL_FALSE, stride, offset);;
	glEnableVertexAttribArray(layout);
    vbo.Unbind();
    Unbind();
}

void VAO::Bind() const {
    glBindVertexArray(ID);
}

void VAO::Unbind() const {
    glBindVertexArray(0);
}

void VAO::Clean() const {
    glDeleteVertexArrays(1, &ID);
}