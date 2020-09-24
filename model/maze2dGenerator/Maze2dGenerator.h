//
// Created by חן גוטמן on 12/08/2020.
//

#ifndef UNTITLED2_MAZE2DGENERATOR_H
#define UNTITLED2_MAZE2DGENERATOR_H


#pragma once

#include "Maze2d.h"
#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Maze2dGenerator {
public:
    virtual Maze2d generate(const string &name,int row, int col) = 0;
    string measureAlgorithmTime(const string &name,int rows, int cols);
};



#endif //UNTITLED2_MAZE2DGENERATOR_H