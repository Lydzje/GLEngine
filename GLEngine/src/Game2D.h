#ifndef GAME_2D_H
#define GAME_2D_H

#include "Game.h"
#include "graphics\Painter2D.h"

class Game2D : public Game
{
public:
    Game2D(unsigned int width = 896, unsigned int height = 504, const char *title = "");
    ~Game2D();

protected:
    void update() const override;
    void render() const override;

private:
    Painter2D m_painter;

};

#endif // !GAME_2D_H
