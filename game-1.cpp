#include "game.h"
#include"grid.h"//
#include"random.h"//
# include <iostream>//
#include "constants.h"

using namespace std;

Game::Game(){
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Big P!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    window.setFramerateLimit(FRAME);// Sets frame limit to a constant value.
    g.PopulateRandom(POP);//populates the grid randomly.

                                        //Gives the user the option to clear the grid.
    clear.setFillColor(sf::Color::Red);// Sets a rectangle shape to the color red.
    clear.setSize(sf::Vector2f(VecX,VecY));//Sets the size of the rectangle to these constants.
    clear.setPosition(XMIN,OGY);// Sets the rectangle at a certain position.

    stopit.setFillColor(sf::Color::Magenta);
    stopit.setSize(sf::Vector2f(VecX,VecY));// Gives the user the option to pause.
    stopit.setPosition(XMIN,VecY+GAP+OGY);// Another option box that lies below the first box.
                                           // Each box below will be displayed at a certain constant value, and a constant distance away from
                                            // the others.

    step.setFillColor(sf::Color::White);//
    step.setSize(sf::Vector2f(VecX,VecY));
    step.setPosition(XMIN,VecY*2+GAP*2+OGY);

    save.setFillColor(sf::Color::Cyan);
    save.setSize(sf::Vector2f(VecX,VecY));
    save.setPosition(XMIN,VecY*3+GAP*3+OGY);

    load.setFillColor(sf::Color::Yellow);
    load.setSize(sf::Vector2f(VecX,VecY));
    load.setPosition(XMIN,VecY*4+GAP*4+OGY);

    populate.setFillColor(sf::Color::Blue);
    populate.setSize(sf::Vector2f(VecX,VecY));
    populate.setPosition(XMIN,VecY*5+GAP*5+OGY);

    go.setFillColor(sf::Color::Green);
    go.setSize(sf::Vector2f(VecX,VecY));
    go.setPosition(XMIN,VecY*6+GAP*6+OGY);

}
void Game::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    DrawOptions();
    DrawGrid();
}
void Game::DrawOptions()
{
    //displays all the option boxes for the user:
    window.draw(clear);
    window.draw(stopit);
    window.draw(step);
    window.draw(save);
    window.draw(load);
    window.draw(populate);
    window.draw(go);
}
void Game::DrawCell(int row, int col, bool life){

    sf::RectangleShape cell(sf::Vector2f(CELLWIDTH,CELLLENGTH));// the set up for the rectangle shaped cell in the grid.

    cell.setPosition(col,row);// the cell position is set.
    if(life==true){

        cell.setFillColor(sf::Color::Green);// the color of live cells.
        window.draw(cell);// Displays cell..

    }
    else{
        cell.setFillColor(sf::Color::Blue);// the color of a dead cell.

        window.draw(cell);// Displays cell..

    }
}
void Game::DrawGrid(){
    //for every cell in my grid, draw that cell:

    int row=0;
    int col=0;
    for (int i=0; i<MAX; i++){
        for (int j = 0; j<MAX; j++){

            row=i*CELLLENGTH+(i-1)*SPACE;// formula to convert the position to the appropriate spot on the grid to be displayed.
            col=j*CELLWIDTH+(j-1)*SPACE;

            DrawCell(row, col, g.IsAlive(i, j));//i is y ;j is x (x,y)

        }
    }
}
void Game::update()
{
    g.Step(); // Function call to show next gernerations.
}
void Game::render(){
    window.clear();// clears
    Draw();// displays
    window.display();
}
void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))//or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        // "close requested" event: we close the window
        case sf::Event::Closed:
            window.close();
            break;

            // key pressed
        case sf::Event::KeyPressed:
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){ //close window when esc is pressed
                window.close();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){ //Randomly populates grid with live cells.
                g.PopulateRandom(POP);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){ //clears grid.
                g.Clear();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){ //Pauses program.
                pause=true;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)){ //Plays program.
                pause=false;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)){ //kills at a specific coordinate
                g.Kill(2,3);
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){ //sets alive at a specific coordinate
                g.SetAlive(5,5);
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){ //Gives next generation
                g.Step();
                pause=true;
            }

            break;

        case sf::Event::MouseButtonReleased:

            // Mouse Clicked :
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                std::cout << "the right button was pressed" << std::endl;
                std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            }
            else if(event.mouseButton.button==sf::Mouse::Left){


                if(event.mouseButton.x>=XSTART+SPACE+VecX &&event.mouseButton.x<=XSTART+SPACE*MAX+MAX*CELLWIDTH &&event.mouseButton.y>=YSTART+SPACE+VecY &&event.mouseButton.y<=YSTART+SPACE*ROW+CELLLENGTH*ROW ){

                    pause=true;

                    int x;//j
                    int y;//i
                    x=((event.mouseButton.x)/(CELLWIDTH+SPACE))+1;
                    y=((event.mouseButton.y)/(CELLLENGTH+SPACE))+1;

                    if(g.IsAlive(y,x)!=true){

                        g.SetAlive(y,x);

                    }

                    else{
                        g.Kill(y,x);
                    }
                }

                if(event.mouseButton.x>=XMIN&&event.mouseButton.x<=XMIN+VecX &&event.mouseButton.y>=OGY&& event.mouseButton.y<=OGY+VecY)
                {
                    g.Clear();
                }

                if(event.mouseButton.x>=XMIN&&event.mouseButton.x<=XMIN+VecX &&event.mouseButton.y>=OGY+VecY+GAP&& event.mouseButton.y<=OGY+VecY*2+GAP)
                {
                    pause=true;
                }

                if(event.mouseButton.x>=XMIN&&event.mouseButton.x<=XMIN+VecX &&event.mouseButton.y>=OGY+VecY*2+GAP*2&& event.mouseButton.y<=OGY+VecY*3+GAP*2)
                {
                    g.Step();
                }
                if(event.mouseButton.x>=XMIN&&event.mouseButton.x<=XMIN+VecX &&event.mouseButton.y>=OGY+VecY*3+GAP*3&& event.mouseButton.y<=OGY+VecY*4+GAP*3)
                {

                    cout<<"Saving..."<<endl;
                    g.Save();
                }
                if(event.mouseButton.x>=XMIN&&event.mouseButton.x<=XMIN+VecX &&event.mouseButton.y>=OGY+VecY*4+GAP*3&& event.mouseButton.y<=OGY+VecY*5+GAP*4)
                {
                    cout<<"Loading..."<<endl;
                    g.Load();
                }

                if(event.mouseButton.x>=XMIN&&event.mouseButton.x<=XMIN+VecX &&event.mouseButton.y>=OGY+VecY*5+GAP*4&& event.mouseButton.y<=OGY+VecY*6+GAP*5)
                {
                    g.PopulateRandom(POP);
                }

                if(event.mouseButton.x>=XMIN&&event.mouseButton.x<=XMIN+VecX &&event.mouseButton.y>=OGY+VecY*6+GAP*5&& event.mouseButton.y<=OGY+VecY*7+GAP*6)
                {
                    pause=false;
                }

                break;
            }
        default:
            break;
        }
    }
}
void Game::run()
{
    while (window.isOpen()&&!pause)

    {
        processEvents();// events processed are either mouse clicked or key pressed.
        update();
        render(); //clear/draw/display

    }
}
void Game::Pause(){
    while(window.isOpen() && pause==true){ // If the private member variable of the game class is set to true the game is paused.
                                            //If false the game plays..
        processEvents();
        render();
    }
}

