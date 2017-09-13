#include "Camera.h"

glm::mat4 Camera::view{};
glm::vec3 Camera::m_position{};
glm::vec3 Camera::m_rotation{glm::radians(90.0f), 0, glm::radians(0.0f)};
glm::vec3 Camera::m_posSpeed{};
glm::vec3 Camera::m_rotFactor{};
float     Camera::m_rotSpeed{};

bool Camera::m_locked{ false };


float* Camera::getViewMatrix()
{

    view = glm::translate(view, 
        glm::vec3(
            m_posSpeed.x * glm::sin(m_rotation.x) + m_posSpeed.z * glm::cos(m_rotation.x),
            m_posSpeed.y,
            m_posSpeed.x * glm::sin(m_rotation.z) + m_posSpeed.z * glm::cos(m_rotation.z)
        )
    );

    view = glm::rotate(view, m_rotSpeed, glm::vec3(0.0f,1.0f,0.0f));
    m_posSpeed *= 0;
    m_rotFactor *= 0;
    m_rotSpeed = 0;

    return glm::value_ptr(view);
}

void Camera::lock(bool locked)
{
    m_locked = locked;
}

void Camera::update()
{
    if (!m_locked)
    {
        if (Input::isKeyPressed(GLFW_KEY_W))
            m_posSpeed.y -= 0.05f;

        if (Input::isKeyPressed(GLFW_KEY_S))
            m_posSpeed.y += 0.05f;
        
        if (Input::isKeyPressed(GLFW_KEY_A))
            m_posSpeed.x += 0.05f;

        if (Input::isKeyPressed(GLFW_KEY_D))
            m_posSpeed.x -= 0.05f;

        if (Input::isKeyPressed(GLFW_KEY_Q))
            m_posSpeed.z += 0.05f;

        if (Input::isKeyPressed(GLFW_KEY_E))
            m_posSpeed.z -= 0.05f;

        if (Input::isKeyPressed(GLFW_KEY_KP_4))
        {
            m_rotation += glm::radians(2.0f);
            m_rotSpeed = glm::radians(2.0f);
        }
        if (Input::isKeyPressed(GLFW_KEY_KP_6))
        {
            m_rotation -= glm::radians(2.0f);
            m_rotSpeed = glm::radians(-2.0f);
        }

    }
}
