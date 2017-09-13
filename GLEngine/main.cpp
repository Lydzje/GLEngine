#include <iostream>

#include <glm\glm.hpp>

#include "examples/GameExample1.h"
#include "src\entities\Entity.h"
int main()
{
    {
        GameExample1 game{};
        game.run();
    }

    std::cin.get();
}