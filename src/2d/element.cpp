#include <iostream>
#include "2d/element.h"
#include "common/vertices.h"
#include "common/utils.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

void Element::Init(Shader& shader, int xPos, int yPos, int width, int height) {
    this->shader = shader;
    this->xPos = xPos;
    this->yPos = yPos;
    this->width = width;
    this->height = height;
    this->activeTexture = 0;

    if (!initialized) {
        vbo = VBO(Vertices::quadVertices, Vertices::quadSize * sizeof(float));
        vao.Bind();
        vao.LinkAttribute(vbo, 0, 2, GL_FLOAT, 4 * sizeof(float), (void*)0);      
        vao.LinkAttribute(vbo, 1, 2, GL_FLOAT, 4 * sizeof(float), (void*)(2 * sizeof(float)));
        vao.Unbind();
        vbo.Unbind();
        initialized = true;
    }
}

bool Element::Click(float mouseX, float mouseY) {
    return mouseX >= xPos && mouseX <= (xPos + width) && 
        mouseY >= yPos && mouseY <= (yPos + height);
};

void Element::Update(int activeTexture) {
    this->activeTexture = activeTexture;
};

void Element::Render(Texture &texture, glm::mat4& projection) {
    this->shader.Use();

    texture.texUnit(this->shader, "image", 0);
    texture.Bind();

    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3((float)xPos, (float)yPos, 0.0f));
    model = glm::scale(model, glm::vec3((float)width, (float)height, 1.0f));
    
    this->shader.SetMat4("projection", projection);
    this->shader.SetMat4("model", model);
    this->shader.SetMat4("view", view);

    vao.Bind();
    glDrawArrays(GL_TRIANGLES, 0, 6);
    vao.Unbind();
};

void Element::Clean() {
    vao.Clean();
    vbo.Clean();
}