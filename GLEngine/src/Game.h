#ifndef GAME_H
#define GAME_H

#include <ctime>
#include <glad\glad.h>

#include "utils\Window.h"
#include "gameplay\GameState.h"


class Game
{
public:
    void run();

    inline float getWidth() { return m_width; }
    inline float getHeight() { return m_height; }
    inline float getRatio() { return (float)m_width / (float)m_height; }

protected:
    unsigned int m_width;
    unsigned int m_height;
    const char* m_title;

    float m_msPerUpdate;

    GameState* m_state;

protected:
    Game(unsigned int width = 896, unsigned int height = 504, const char *title = "");
    virtual ~Game();

    void init();
    virtual void update() const;
    virtual void render() const = 0;

};

#endif // !GAME_H



