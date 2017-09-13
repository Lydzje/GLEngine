#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <iostream>

#include "IState.h"

class GameState : public IState
{
public:
    GameState();
    virtual ~GameState();

    virtual void update() override;
    virtual void begin() override;
    virtual void end() override;
};

#endif // !GAME_STATE_H




