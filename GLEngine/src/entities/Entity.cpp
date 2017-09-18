#include "Entity.h"

#include <iostream>
#include <glm\gtc\matrix_transform.hpp>

std::vector<Entity*>Entity::s_entities{};

Entity::Entity(const glm::vec3& position, const glm::vec3& rotation, const glm::vec2& scale, Sprite* sprite)
    : Drawable2D(sprite), m_position(position), m_rotation(rotation), m_scale(scale),
    m_transformation(glm::mat4())
{
    s_entities.push_back(this);

    m_transformation = glm::translate(m_transformation, m_position);
    m_transformation = glm::rotate(m_transformation, glm::radians(m_rotation.x), glm::vec3(1, 0, 0));
    m_transformation = glm::rotate(m_transformation, glm::radians(m_rotation.y), glm::vec3(0, 1, 0));
    m_transformation = glm::rotate(m_transformation, glm::radians(m_rotation.z), glm::vec3(0,0,1));
    m_transformation = glm::scale(m_transformation, glm::vec3(m_scale.x, m_scale.y, 0));

    std::cout << "Entity created!\n";
}

Entity::~Entity()
{
    std::cout << "Entity destroyed!\n";
}
