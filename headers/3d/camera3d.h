#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

const float YAW         = -90.0f;
const float PITCH       =  0.0f;
const float SPEED       =  2.5f;
const float SENSITIVITY =  100.0f;
const float ZOOM        =  45.0f;

class Camera3d {
    public:
        // camera Attributes
        glm::vec3 Position;
        glm::vec3 Front;
        glm::vec3 Up;
        glm::vec3 Right;
        glm::vec3 WorldUp;

        // euler Angles
        float Yaw;
        float Pitch;

        // camera options
        float MovementSpeed;
        float MouseSensitivity;
        float Zoom;

        Camera3d();
        glm::mat4 GetViewMatrix();
        void HandleInput(Camera_Movement direction, float deltaTime);
        void HandleRotation(float xoffset, float yoffset, float deltaTime);
        void ProcessMouseScroll(float yoffset);

    private:
        void UpdateCamera();
};
#endif