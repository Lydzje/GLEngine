#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include "../GameState.h"
#include "../../graphics/Sprite.h"

class TestScene : public GameState
{
public:
    TestScene();
    ~TestScene();

    void begin() override;
    void update() override;
    void end() override;

private:
    SpriteSheet m_sh;
    Sprite m_s;

};

#endif // !TEST_SCENE_H
