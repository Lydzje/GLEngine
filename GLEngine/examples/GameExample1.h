#ifndef GAME_EXAMPLE1_H
#define GAME_EXAMPLE1_H

#include "../src/Game2D.h"

class GameExample1 : public Game2D
{
public:
    GameExample1(unsigned int width = 896, unsigned int height = 504, 
        const char *title = "");
    ~GameExample1() override;
};

#endif // !GAME_EXAMPLE1_H
