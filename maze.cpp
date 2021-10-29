/*

Your Name
CSCI 3110-00X (your section #)
Project #X
Due: mm/dd/yy


*/


/*
this file contains implementation of header file maze.h
all of the functions declared in header file are implemented here.
this file contains methods or functions that will helps in finding exit
*/

//imports
#include "maze.h"
#include <iostream>
#include <fstream>
using namespace std;


//defining class members
//this is definition of constructor, it will open and read file to construct maze
Maze::Maze(){
    int mazeSize = sizeof(maze[0])/sizeof(maze[0][0]); //reading dynamically size of maze map
    //now lets read maze configurations from file
    fstream fileInp;
    fileInp.open("src/maze.txt");
    if(fileInp.is_open()){
        getline(fileInp, xplor); //reading order of exploration
        fileInp>>maxRows>>maxCols; //reading size of maze
        //lets setup maze boundary
        int size = maxRows+2;
        for(int i=0; i < size;i++){
            for(int j=0; j < size; j++){
                if(i==0 || j == 0 || i == size-1|| j == size-1){
                maze[i][j] = 'X';
                }
                else{
                    maze[i][j] = ' ';
                }
            }
        }
        
        //lets fill up maze
        string line;
        int x = 1;
        int y = 1;
        bool flag = false;
        while(getline(fileInp, line)){
            for(int i=0; i<line.size(); i++){
                if((int)line[i]!=13){
                    maze[x][y] = line[i];
                    y+=1;   
                    flag = true;
                }
            }
            if(flag){
                x+=1;
                y=1;
                flag = false;
            }
            
        }
        
        
        //closing file
        fileInp.close();
    }
    else{
        cout<<"Failed to open file\n";
        exit(-1);
    }
}

//this function will helps in printing current state of maze
void Maze::Print(){
    cout<<"Maze State:\n";
    for(int i=1; i<=maxRows; i++){
        cout<<"  ";
        for(int c=1; c<=maxRows; c++){
            cout<<maze[i][c]<<"";
        }
        cout<<endl;
    }
}

//this function is recursive function, which will exhaust all possible paths to find exit
void Maze::FindExit(int r, int c, bool& found){

    if(maze[r][c]=='O'){
        cout<<"Exploring "<<r<<","<<c<<endl;
        maze[r][c] = '*';
        Print();
        for(int i=0; i<xplor.size(); i++){
            pair<int, int> p = getMove(xplor[i]);
            int x = r + p.first;
            int y = c + p.second;
            FindExit(x,y,found);
            
        }
    }
    else if(maze[r][c] == 'E'){
        cout<<"Exploring "<<r<<","<<c<<endl;
        found = true;  
    }
    else;
  }
   

//this function will helps in getting current move, move can be diagonally
pair<int, int> Maze::getMove(char ch){
    pair<int, int> p;
    if(ch == '1'){
        p.first = -1;
        p.second = -1;
    }
    else if(ch == '2'){
        p.first = -1;
        p.second = 1;
    }
    else if(ch == '3'){
        p.first = 1;
        p.second = 1;
    }
    else{
        p.first = 1;
        p.second = -1;
    }
    return p;
}


