#include "TestScene.h"

#include <iostream>

#include "../../entities/Entity.h"

TestScene::TestScene()
    : m_sh(SpriteSheet("res\\images\\test.jpg")), m_s(Sprite(0, 0, m_sh))
{
    // Consider a loadResources() function for states

    begin();
    std::cout << "TestScene created!\n";
}

TestScene::~TestScene()
{
    end();
    std::cout << "TestScene destroyed!\n";
}

void TestScene::begin()
{
    for (int y = 0; y < 30; y++)
        for (int x = 0; x < 30; x++)
            new Entity(glm::vec3(1.0f * (x), -1 * (y), -10.5f), glm::vec3(0, 0, 0), glm::vec2(0.75f, 0.75f), &m_s);
}

void TestScene::update()
{
}

void TestScene::end()
{
    for each (Entity* e in Entity::s_entities)
        delete e;

    Entity::s_entities.clear();
}
