#ifndef GRID_H
#define GRID_H
#include "constants.h"
#include <iostream>
using namespace std;


class Grid
{
public:
    Grid();//initializes private member variale the array.

    void ClearAny(int a1[][MAX]);
    bool IsAlive(int i, int j);//tells if a cell is alive or dead
    void Show();//will print the grid on the screen
    void Clear();//Sets every spot in a 2d array to zero.

    //Mutators:
    void SetAlive(int i,int j);//Sets a specific spot in a 2d array to 1.
    void Kill(int i, int j);//Sets a specific spot in a 2d array to 0.
    int CountNeighbors(int i, int j);//Will tell you the number of alive cells for that given cell.
    void SwitchTemp(int temp[][MAX]);// Switches arrays.
    void CopyArray(int t[][MAX]);
    void Step();//will generate the next generation on the grid.
    void PopulateRandom(int r);//will add live cells to the grid randomly.

    void Load();
    void Save();

private:
    int a[ROW][MAX];//used to store live cells.

};

#endif // GRID_H
