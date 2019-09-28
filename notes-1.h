#ifndef NOTES_H
#define NOTES_H

/*

Notes:

    My Grid class contains all the lower level functions of this program. This aspect of the
program works directly with the 2d Array. The functions do this such as clear the 2d array, set values to one,
 set values to zero, it checks what the value of a cell is, counts the number of cells that are of value one around a specific
 cell, and other features. My program also uses a random class the is called by my grid class. These functions will all be called
by upper functions in the Game class.

    The features of my Game class are render,update,process events, draw, draw cell,draw grid, pause, and draw options. The Draw function
actually displays the grid and cells. The Draw grid forms the actual grid on the window by calling Draw cell to draw each individual cell.
These two functions are both called by Draw. Draw also call draw options which displays the boxes displayed for the user to manipulate the grid,
and the game. Process events has many cases, depending on what the user actually does. There are key pressed events and mouse button events.
The key pressed events works very much like the average switch statment we've done in earlier programs. Depending on which key the user enters,
the program will call a specific function and do a certain task according to the key pressed. The mouse button events all depend on where exactly
the user left clicks. By where I mean where in the actual window. If the user clicks on a cell in the grid it either becomes alive or dead
depending on if it was dead or alive before. If the user clicks on the option boxes, depending on what box they click on a specific task will be
performed. My pause function has a private member variable of type bool. If it equals true the program pauses, if it is false then the program
resumes. The majority of these features call my lower level functions in my grid class to perform some tasks necessary for the Game class
to run.

    In my Game class I had to consider many different things. First, I had to consider that the position in my Game class was in terms of the
actual display window, not the indexes in the 2d array. I also had to consider that the actual grid wasn't of the size ROW by MAX like it was
in my grid class. Another thing I had to consider was where each actual cell was located on the window because it was different than that of
the array in my grid class. I had to use mathematics to solve all these problems.

    The math I had to use in my program were mostly for the graphics portion of the project.The first formula I had to consider was how to
find the actual coordinates of each cell in the grid. I called my draw cell in a double for loop that starts at zero and ends at max. The draw cell
takes in the row and clummn, and a boolean expression to find the live cells. The row and column are different than that of arrays. The formula
I used to solve the actual coordinate was I multiplied my vector vecotor constants for the width and height of each cell by the values incremented
in my for loop. I multiple the height of the cell by i which works as the row in a normal 2D array. I multiplied the width of the cell by j which
works as the column in a 2D array. This takes into account the actual position accoding to how big the cell is,and the actual spot it lies on the
screen.I also multiplied both by a constant called space, just to give each cell some empty space from all the other cells.

    I had to use some more math to figure out where to place my option menu on the window. The window has several rectangles on the right hand sign
each with its own unique comand that it can perform for the user. The way I found out where to place these rectangles and how to keep them alligned
is I began with the original rectangle at a constant width and height. I included a gap constant to give each rectangle space. My rectangles were
placed at and origial y constant and it ended at the vector height plus that position. The next rectangle would begin at the original y position
plus the vector height and the gap. The next rectangles would have the hieght multiplied by how many rectangles and the gap multiplie by how many
gaps are there. This would all be added to that original y spot on the grid. The width of each rectangle would all start at a certain value and end
at the same value so all the rectangles were equivalent in width.

    I also used math to determine how the user can do certain comands by just clicking on the appropriate comand box. I placed each of the boxes in a
specific position, and the rest followed right under the one above. I had to figure out exactly where I wanted to put these boxes and which value would
stay the same, and which would change. Because I wanted them to all be lined up above each other the position of each box horizontally would be the same.
But each boxes position vertically would change because each box cannot be displayed at the same exact position.

    I also had to figure out at what position on the actual window does the grid lie. It was simple math but I started at the first
cell and ended at the number of cells in the row which is the constant ROW multiplied by the width of the actual cell all added by the
size of each space in the grid multiplied by the constant ROW.

*/

#endif // NOTES_H
