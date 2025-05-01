#include "3d/camera3d.h"

Camera3d::Camera3d() {
    Position = glm::vec3(0.0f, 0.0f, 5.0f);
    WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
    Front = glm::vec3(0.0f, 0.0f, -1.0f);

    Yaw = YAW;
    Pitch = PITCH;

    MovementSpeed = SPEED;
    MouseSensitivity = SENSITIVITY;
    Zoom = ZOOM;
    
    UpdateCamera();
}

glm::mat4 Camera3d::GetViewMatrix() {
    return glm::lookAt(Position, Position + Front, Up);
}

void Camera3d::HandleInput(Camera_Movement direction, float deltaTime) {
    float velocity = MovementSpeed * deltaTime;
    if (direction == FORWARD)
        Position += Front * velocity;
    if (direction == BACKWARD)
        Position -= Front * velocity;
    if (direction == LEFT)
        Position -= Right * velocity;
    if (direction == RIGHT)
        Position += Right * velocity;
}

void Camera3d::ProcessMouseScroll(float yoffset) {
    Zoom -= (float)yoffset;
    if (Zoom < 1.0f)
        Zoom = 1.0f;
    if (Zoom > 45.0f)
        Zoom = 45.0f;
}

void Camera3d::HandleRotation(float xoffset, float yoffset, float deltaTime) {
    xoffset *= MouseSensitivity*deltaTime;
    yoffset *= MouseSensitivity*deltaTime;

    Yaw   -= xoffset;
    Pitch -= yoffset;

    if (Pitch > 89.0f) Pitch = 89.0f;
    if (Pitch < -89.0f) Pitch = -89.0f;

    UpdateCamera();
}

void Camera3d::UpdateCamera() {
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);
    
    Right = glm::normalize(glm::cross(Front, WorldUp));
    Up    = glm::normalize(glm::cross(Right, Front));
}