#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include "common/vertices.h"
#include "canvas3d.h"

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
glm::quat modelRotation = glm::quat(1, 0, 0, 0);

static bool firstMouse = true;
static double lastX = 0.0f;
static double lastY = 0.0f;

Canvas3d::Canvas3d(int width, int height) {
    this->activeModel = 1;
    this->activeLight = 3;
    this->width = width;
    this->height - height;
    this->shader = Shader("./shaders/cube.vert", "./shaders/cube.frag");

    this->texture1 = Texture("./textures/wood.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE, GL_RGBA, true);
    this->texture2 = Texture("./textures/scifi.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE, GL_RGBA, true);
    this->texture3 = Texture("./textures/greeny.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE, GL_RGBA, true);

    modelVbo1 = VBO(Vertices::cube, Vertices::cubeSize * sizeof(float));
    modelVao1.Bind();
    modelVao1.LinkAttribute(modelVbo1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);              // position
    modelVao1.LinkAttribute(modelVbo1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float))); // normals
    modelVao1.LinkAttribute(modelVbo1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float))); // texCoords
    modelVao1.Unbind();
}

void Canvas3d::HandleInput(GLFWwindow *window, float deltaTime) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.HandleInput(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.HandleInput(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.HandleInput(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.HandleInput(RIGHT, deltaTime);

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        if (firstMouse) {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        float xoffset = xpos - lastX;
        float yoffset = ypos - lastY;

        lastX = xpos;
        lastY = ypos;

        HandleModelRotation(xoffset, yoffset, deltaTime);
    } else {
        firstMouse = true;
    }
}

void Canvas3d::Render() {
    this->shader.Use();
    this->shader.SetInt("activeLight", this->activeLight);

    if(this->activeModel == 1) {
        this->texture1.texUnit(this->shader, "image", 0);
        this->texture1.Bind();
    } else if (this->activeModel == 2) {
        this->texture2.texUnit(this->shader, "image", 0);
        this->texture2.Bind();
    } else if (this->activeModel == 3) {
        this->texture3.texUnit(this->shader, "image", 0);
        this->texture3.Bind();
    }

    this->shader.SetVec3("objectColor", 0.3020f, 0.0588f, 0.0588f);
    this->shader.SetVec3("lightColor", 1.0f, 1.0f, 1.0f);
    this->shader.SetVec3("viewPos", camera.Position);
    this->shader.SetVec3("lightPos", lightPos);

    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), 900.0f / 533.0f, 0.1f, 100.0f);
    glm::mat4 view = camera.GetViewMatrix();
    glm::mat4 model = glm::mat4(1.0f);
    model *= glm::mat4_cast(modelRotation);

    shader.SetMat4("projection", projection);
    shader.SetMat4("view", view);
    shader.SetMat4("model", model);

    modelVao1.Bind();
    glDrawArrays(GL_TRIANGLES, 0, 36);
    modelVao1.Unbind();
}

void Canvas3d::HandleModelRotation(float xoffset, float yoffset, float deltaTime) {
    xoffset *= 100.0f * deltaTime;
    yoffset *= 100.0f * deltaTime;

    glm::vec3 upAxis(0.0f, 1.0f, 0.0f);
    glm::vec3 rightAxis(1.0f, 0.0f, 0.0f);

    glm::quat yaw = glm::angleAxis(glm::radians(xoffset), upAxis);
    glm::quat pitch = glm::angleAxis(glm::radians(yoffset), rightAxis);

    modelRotation = glm::normalize(yaw * pitch * modelRotation);
}

void Canvas3d::Clean() {
    modelVao1.Clean();
    modelVbo1.Clean();
}
