#include "Camera.h"

#include <iostream>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "Input.h"

glm::mat4 Camera::s_view{};
glm::vec3 Camera::s_position{};
glm::vec3 Camera::s_rotation{glm::radians(90.0f), 0, glm::radians(0.0f)};
glm::vec3 Camera::s_posSpeed{};
glm::vec3 Camera::s_rotFactor{};
float     Camera::s_rotSpeed{};

bool Camera::s_locked{ false };


float* Camera::get_view_matrix()
{

    s_view = glm::translate(s_view, 
        glm::vec3(
            s_posSpeed.x * glm::sin(s_rotation.x) + s_posSpeed.z * glm::cos(s_rotation.x),
            s_posSpeed.y,
            s_posSpeed.x * glm::sin(s_rotation.z) + s_posSpeed.z * glm::cos(s_rotation.z)
        )
    );

    s_view = glm::rotate(s_view, s_rotSpeed, glm::vec3(0.0f,1.0f,0.0f));
    s_posSpeed *= 0;
    s_rotFactor *= 0;
    s_rotSpeed = 0;

    return glm::value_ptr(s_view);
}

void Camera::lock(bool locked)
{
    s_locked = locked;
}

void Camera::update()
{
    if (!s_locked)
    {
        if (Input::is_key_pressed(GLFW_KEY_W))
            s_posSpeed.y -= 0.05f;

        if (Input::is_key_pressed(GLFW_KEY_S))
            s_posSpeed.y += 0.05f;
        
        if (Input::is_key_pressed(GLFW_KEY_A))
            s_posSpeed.x += 0.05f;

        if (Input::is_key_pressed(GLFW_KEY_D))
            s_posSpeed.x -= 0.05f;

        if (Input::is_key_pressed(GLFW_KEY_Q))
            s_posSpeed.z += 0.05f;

        if (Input::is_key_pressed(GLFW_KEY_E))
            s_posSpeed.z -= 0.05f;

        if (Input::is_key_pressed(GLFW_KEY_KP_4))
        {
            s_rotation += glm::radians(2.0f);
            s_rotSpeed = glm::radians(2.0f);
        }
        if (Input::is_key_pressed(GLFW_KEY_KP_6))
        {
            s_rotation -= glm::radians(2.0f);
            s_rotSpeed = glm::radians(-2.0f);
        }

    }
}
