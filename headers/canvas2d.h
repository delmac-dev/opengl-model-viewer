#ifndef CANVAS2D_H
#define CANVAS2D_H

#include "canvas3d.h"
#include "2d/element.h"
#include <GLFW/glfw3.h>

class Canvas2d {
    public:
        Canvas2d(Canvas3d* modelCanvas, int width, int height);
        void HandleInput(GLFWwindow *window, float deltaTime);
        void Update();
        void Render();
        void Clean();
    
    private:
        Shader shader;
        Canvas3d* modelCanvas;

        glm::mat4 projection = glm::mat4(1.0f);

        Element background;

        Element modelSelector1;
        Element modelSelector2;
        Element modelSelector3;

        Element lightSelector1;
        Element lightSelector2;
        Element lightSelector3;

        Texture bgTexture;
        Texture buttonTexture1;
        Texture buttonActiveTexture1;
        Texture buttonTexture2;
        Texture buttonActiveTexture2;
        Texture buttonTexture3;
        Texture buttonActiveTexture3;
};
#endif