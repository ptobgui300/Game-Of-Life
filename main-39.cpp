/* Program: Game of Life
   Author: Pierre Tobgui
   Program Desription: Is  found in the Notes header file.
*/

#include <iostream>
#include "game.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    Game mygame;
    int i=0;
    while(i==0){ // Keeps the game from ending every time the game is paused and play is pressed.
        mygame.run();
        mygame.Pause();

    }
    return 0;
}
