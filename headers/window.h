#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
    public:
        Window(int width, int height, float targetFPS);
        ~Window();

        void Clear(float r, float g, float b, float a);
        void SwapBuffers();
        void PollEvents();
        void SetFrameRate();
        bool ShouldClose() const;

        float GetDeltaTime();

        GLFWwindow* GetGLFWwindow() const;

        GLFWwindow* window;
        int width, height;
        float targetFPS;
        float deltaTime, lastFrame;
};
#endif