#ifndef CAMERA_H
#define CAMERA_H

#include <glm\glm.hpp>

class Camera
{

public:
    static float* get_view_matrix();
    static void lock(bool locked);
    static void update();

private:
    static glm::mat4 s_view;
    static glm::vec3 s_position;
    static glm::vec3 s_rotation;
    static glm::vec3 s_posSpeed;
    static glm::vec3 s_rotFactor;
    static float     s_rotSpeed;

    static bool s_locked;

private:
    Camera() = delete;
};

#endif // !CAMERA_H
