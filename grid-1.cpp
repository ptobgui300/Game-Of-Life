#include "grid.h"
#include <iostream>
#include"random.h"
#include<time.h>
#include "constants.h"
#include<fstream>

using namespace std;

Grid::Grid(){
    Clear();//Grid class constructor.
            //Sets the whole grid to zero.
}
void Grid::PopulateRandom(int r){//r is number of live cells added randomly to grid.

    random part;
    for(int i=0;i<r;i++){
        a[part.GetNext(2,MAX-2)][part.GetNext(2,MAX-2)]=1;
    }
}
void Grid::Show(){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<MAX;j++){

            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}
bool Grid::IsAlive(int i,int j){
    if (a[i][j]==1){ // if the value in the 2d array is 1 at the specific coordinate it is declared alive by returning true.
        return true;
    }
    else{
        return false;// Any value other than 1 in the 2d array is considered a dead coordinate.
    }
}
void Grid::Clear(){
    for(int i=0;i<ROW;i++){ // sets all values in the 2d array to 0.
        for(int j=0;j<MAX;j++){
            a[i][j]=0;
        }
    }
}
void Grid::ClearAny(int a1[][MAX]){ // Sets values in a 2d array to 0.
    for(int i=0;i<ROW;i++){
        for(int j=0;j<MAX;j++){
            a1[i][j]=0;
        }
    }
}
void Grid::Step(){
    int alive;

    int temp[ROW][MAX]; //temporary array to do changes to before doing to the original array.
                        // Used to avoid errors in the program.
                         // Rules, and game can't have changes made as the program checks, must all happen at once.

    ClearAny(temp);//initializing temporary array to all zeros.
    for(int i=1;i<ROW-1;i++){//
        for(int j=1;j<MAX-1;j++){//1 to max-1 so it doesn't count row 0 or column 0 or last column and last row.

            alive=CountNeighbors(i,j);// The integer alive is how many live cells are around one specific cell.

            if(alive<2){
                temp[i][j]=0;
            }

            if(alive==3){
                temp[i][j]=1;
            }
            if (alive==2){
                temp[i][j] = a[i][j];
            }
            if(alive>3){
                temp[i][j]=0;
            }
        }
    }

    CopyArray(temp); //copy's changes made into original array.

}
void Grid::CopyArray(int t[][MAX]){

    for(int i =0;i<ROW;i++){
        for(int j=0;j<MAX;j++){
            a[i][j]=t[i][j];
        }
    }
}
void Grid::SetAlive(int i,int j){

    if(i >0 && j >0 &&i<MAX-1 &&j<MAX-1){
        a[i][j]=1; // Sets a cell to one which means it is alive.
                   // Cannot set a cell to alive if it's row is 0 or MAX-1.
                    // Cannot set a cell to alive if it's column is 0 or MAX-1.
                    // Rows and columns cannot have live cells in 0 or MAX-1 so unnessecary errors won't occur.
    }
}
void Grid::Kill(int i,int j){
    a[i][j]=0; //sets a specific spot in the array to 0.
}
int Grid::CountNeighbors(int i,int j){
    int itSelf;
    int total=0;

    itSelf=a[i][j];
    for(int row=i-1;row<i+2;row++){
        for(int column=j-1;column<j+2;column++){

            if(IsAlive(row,column)==true){
                total++;
            }
        }
    }

    total-=itSelf;
    return total; //Returns the number of cells that are of the value 1 around a specific cell.
}
void Grid::Load(){

    int num;
    int i=0;
    int j=0;
    ifstream file1;// Declaring file.
    file1.open("myFile");// opening file.

    if (file1.fail()){ // Checking for fail.
        cout<<"open file failed..."<<endl; // error message if file did not open.
        exit(1);
    }
    for(int i=0;i<ROW;i++){
        for(int j=0;j<MAX;j++){
            file1>>a[i][j];
        }

    }
    file1.close();//  File closed..
}
void Grid::Save(){

    ofstream file1; // declaring file.
    file1.open("myFile");// opening file.
    if(file1.fail())// checking for fail.
    {
        cout<<"couldn't open file for output "<<endl; // error message..
        exit(0);
    }

    file1<<ROW;
    file1<<MAX;
    for(int i=0;i<ROW;i++){
        for(int j=0;j<MAX;j++){
            file1<<a[i][j]<<" ";
        }
    }
    file1.close();// File closed..
}
