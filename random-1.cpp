#include "random.h"
#include<iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//----------------------------------------------------------------------
//initialization of the static member variable must be done in the .cpp file.
//
int random::objectCount=0;
//
//----------------------------------------------------------------------
random::random(){
    objectCount++;
    if (objectCount==1){
        //cout<<endl<<"random number generator seeded..."<<endl;
        //-----------------------------------------------
        srand(time(0)); //this is bad!!//
    }
}
int random::GetNext(int lo, int hi){
    int r = (rand()%(hi-lo+1)+lo);
    return r;
}
