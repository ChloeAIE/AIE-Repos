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
} //Comment to have something to merge! ^_^
  // And this one for pull request ;_;