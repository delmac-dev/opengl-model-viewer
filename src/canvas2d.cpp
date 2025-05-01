#include "canvas2d.h"

Canvas2d::Canvas2d(Canvas3d* modelCanvas, int width, int height) {
    this->modelCanvas = modelCanvas;

    this->projection = glm::ortho(0.0f, (float)width, (float)height, 0.0f, -1.0f, 1.0f); // (0,0) top-left

    this->shader = Shader("./shaders/element.vert", "./shaders/element.frag");
    this->bgTexture = Texture("./textures/background.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE, GL_RGBA, false);
    this->buttonTexture1 = Texture("./textures/button1.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE, GL_RGBA, false);
    this->buttonActiveTexture1 = Texture("./textures/button_active1.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE, GL_RGBA, false);
    this->buttonTexture2 = Texture("./textures/button2.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE, GL_RGBA, false);
    this->buttonActiveTexture2 = Texture("./textures/button_active2.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE, GL_RGBA, false);
    this->buttonTexture3 = Texture("./textures/button3.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE, GL_RGBA, false);
    this->buttonActiveTexture3 = Texture("./textures/button_active3.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE, GL_RGBA, false);

    background.Init(shader, 0, 0, width, height);
    
    modelSelector1.Init(shader, 816, 283, 64, 64);
    modelSelector2.Init(shader, 816, 361, 64, 64);
    modelSelector3.Init(shader, 816, 439, 64, 64);

    lightSelector1.Init(shader, 8, 24, 48, 48);
    lightSelector2.Init(shader, 8, 87, 48, 48);
    lightSelector3.Init(shader, 8, 150, 48, 48);
}

void Canvas2d::HandleInput(GLFWwindow *window, float deltaTime) {
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        double mouseX, mouseY;
        glfwGetCursorPos(window, &mouseX, &mouseY);

        if (modelSelector1.Click((float)mouseX, mouseY)) modelCanvas->activeModel = 1;
        else if (modelSelector2.Click((float)mouseX, mouseY)) modelCanvas->activeModel = 2;
        else if (modelSelector3.Click((float)mouseX, mouseY)) modelCanvas->activeModel = 3;

        if (lightSelector1.Click((float)mouseX, mouseY)) modelCanvas->activeLight = 1;
        else if (lightSelector2.Click((float)mouseX, mouseY)) modelCanvas->activeLight = 2;
        else if (lightSelector3.Click((float)mouseX, mouseY)) modelCanvas->activeLight = 3;
    }
};

void Canvas2d::Update() {
    modelSelector1.Update(modelCanvas->activeModel == 1 ? 1 : 0);
    modelSelector2.Update(modelCanvas->activeModel == 2 ? 1 : 0);
    modelSelector3.Update(modelCanvas->activeModel == 3 ? 1 : 0);

    lightSelector1.Update(modelCanvas->activeLight == 1 ? 1 : 0);
    lightSelector2.Update(modelCanvas->activeLight == 2 ? 1 : 0);
    lightSelector3.Update(modelCanvas->activeLight == 3 ? 1 : 0);
};

void Canvas2d::Render() {
    background.Render(bgTexture, projection);
    modelSelector1.Render(!modelSelector1.activeTexture? buttonTexture1 : buttonActiveTexture1, projection);
    modelSelector2.Render(!modelSelector2.activeTexture? buttonTexture2 : buttonActiveTexture2, projection);
    modelSelector3.Render(!modelSelector3.activeTexture? buttonTexture3 : buttonActiveTexture3, projection);
    lightSelector1.Render(!lightSelector1.activeTexture? buttonTexture1 : buttonActiveTexture1, projection);
    lightSelector2.Render(!lightSelector2.activeTexture? buttonTexture2 : buttonActiveTexture2, projection);
    lightSelector3.Render(!lightSelector3.activeTexture? buttonTexture3 : buttonActiveTexture3, projection);
};

void Canvas2d::Clean() {
    background.Clean();
    modelSelector1.Clean();
    modelSelector2.Clean();
    modelSelector3.Clean();
    lightSelector1.Clean();
    lightSelector2.Clean();
    lightSelector3.Clean();

    bgTexture.Delete();
    buttonTexture1.Delete();
    buttonActiveTexture1.Delete();
    buttonTexture2.Delete();
    buttonActiveTexture2.Delete();
    buttonTexture3.Delete();
    buttonActiveTexture3.Delete();
    
    delete modelCanvas;
}
