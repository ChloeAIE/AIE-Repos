#include <iostream>
#include "Game.h"

int main()
{
    Game* game = new Game(); //instance of Game
  
    while (true) //runs the game
    {
        game->DrawMap();
        game->RunGame();
    }
}