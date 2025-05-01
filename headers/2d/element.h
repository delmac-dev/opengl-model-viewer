#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <vector>
#include "common/shader.h"
#include "common/texture.h"
#include "common/vao.h"
#include "common/vbo.h"

using std::vector;
using std::string;

class Element {
    public:
        Shader shader;
        unsigned int xPos, yPos, width, height;
        unsigned int activeTexture;
        
        Element() = default;
        void Init(Shader& shader, int xPos, int yPos, int width, int height);
        bool Click(float mouseX, float mouseY);
        void Update(int activeTexture);
        void Render(Texture &texture, glm::mat4& projection);
        void Clean();

    private:
        VAO vao;
        VBO vbo;
        bool initialized = false;
};
#endif