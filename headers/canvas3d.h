#ifndef CANVAS3D_H
#define CANVAS3D_H

#include "3d/camera3d.h"
#include "common/shader.h"
#include "common/texture.h"
#include "common/vao.h"
#include "common/vbo.h"
#include <GLFW/glfw3.h>

class Canvas3d {
    public:
        unsigned int activeModel;
        unsigned int activeLight;

        unsigned int width, height;
        
        Shader shader;
        Texture texture1;
        Texture texture2;
        Texture texture3;
        Camera3d camera;
        VAO modelVao1;
        VBO modelVbo1;

        Canvas3d(int width, int height);
        void HandleInput(GLFWwindow *window, float deltaTime);
        void Render();
        void HandleModelRotation(float xoffset, float yoffset, float deltaTime);
        void Clean();
};
#endif