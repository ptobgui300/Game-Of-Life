#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "constants.h"
#include "grid.h"
using namespace std;

class Game{
public:
    Game();
    void Draw();
    void run();
    void processEvents();
    void update();
    void render();
    void DrawCell(int row, int col, bool life);
    void DrawGrid();
    void Pause();
    void DrawOptions();

    sf::RectangleShape clear;
    sf::RectangleShape go;
    sf::RectangleShape step;
    sf::RectangleShape stopit;
    sf::RectangleShape save;
    sf::RectangleShape load;
    sf::RectangleShape populate;
    sf::Text text;
    sf::Font font;

private:
    sf::RenderWindow window;
    Grid g;
    bool pause=true;
};

#endif // GAME_H
