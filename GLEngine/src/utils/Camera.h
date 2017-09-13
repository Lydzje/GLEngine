#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "Input.h"

class Camera
{

public:
    static float* getViewMatrix();
    static void lock(bool locked);
    static void update();

private:
    static glm::mat4 view;
    static glm::vec3 m_position;
    static glm::vec3 m_rotation;
    static glm::vec3 m_posSpeed;
    static glm::vec3 m_rotFactor;
    static float     m_rotSpeed;

    static bool m_locked;

private:
    Camera() = delete;
};

#endif // !CAMERA_H



