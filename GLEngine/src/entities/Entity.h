#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "Drawable2D.h"

class Entity : public Drawable2D // TEMPORAL
{
public:
    static std::vector<Entity*> s_entities;

public:
    Entity(const glm::vec3& position, const glm::vec3& rotation, const glm::vec2& scale,
        Sprite* sprite);
    ~Entity();

    inline float* getModelMatrix() { return glm::value_ptr(m_transformation); }
    inline glm::mat4 getModelMatrixGLM() { return m_transformation; }

private:
    glm::mat4 m_transformation;

    glm::vec3 m_position;
    glm::vec3 m_rotation;
    glm::vec2 m_scale;

};

#endif // !ENTITY_H
