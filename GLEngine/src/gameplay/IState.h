#ifndef I_STATE_H
#define I_STATE_H

class IState
{
public:
    virtual void update() = 0;
    virtual void begin() = 0;
    virtual void end() = 0;

protected:
    IState() {};
    virtual ~IState() {};

};

#endif // !GAME_STATE_H
