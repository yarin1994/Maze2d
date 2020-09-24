//
// Created by חן גוטמן on 24/08/2020.
//

#ifndef UNTITLED3_MODEL_H
#define UNTITLED3_MODEL_H

#include <string>
#include <iostream>
#include "./maze2dGenerator/Maze2d.h"
#include "./maze2dGenerator/Position.h"
#include "./Observable.h"
#include "./search/Solution.h"
#include "./Demo/Demo.h"
#include "./maze2dGenerator/MazeCompression.h"

using namespace std;

class Model : public Observable {
    virtual void generateAlgoMaze(string name, int rows , int cols)=0;
    virtual void generateSimpleMaze(string name, int rows , int cols)=0;
    virtual void getMaze(string name)=0;
    virtual void getSizeMaze(string name)=0;
    virtual void getFileSize(string name)=0;
    virtual void displaySolution(string name,string alg)=0;
    virtual void saveMaze(ofstream *output,string name)=0;
    virtual void solveBFSMaze(string name,string alg)=0;
    virtual void solveAstarMaze(string name,string alg,string astarType)=0;
    virtual void loadMaze(ifstream *input,string name="")=0;

};
#endif //UNTITLED3_MODEL_H
