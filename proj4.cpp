/*

Your Name
CSCI 3110-00X (your section #)
Project #X
Due: mm/dd/yy


*/

//this is a driver file, it instantiates maze and call FindExit method to find
//exit is reachable or not.

#include "maze.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv){

    Maze m;
    m.Print();//displaying initial state of maze
    //calling Find Exit method now
    bool found = false;
    cout<<"Starting Position: 1,1\n";
    m.FindExit(1,1,found);

    //checking whether exit found or not
    if(found){
        cout<<"Found Exit!\n";
    }
    else{
        cout <<"No Exit!\n";
    }
    
    return 0;
}