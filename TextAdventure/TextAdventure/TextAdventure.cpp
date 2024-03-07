#include <iostream>
#include "Game.h"

int main()
{
    Game* game = new Game();
  
    while (true)
    {
        game->DrawMap();
        game->RunGame();
    }
}