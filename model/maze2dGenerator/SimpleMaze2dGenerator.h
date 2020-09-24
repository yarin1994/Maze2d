//
// Created by חן גוטמן on 12/08/2020.
//

#ifndef UNTITLED2_SIMPLEMAZE2DGENERATOR_H
#define UNTITLED2_SIMPLEMAZE2DGENERATOR_H


#include "Maze2dGenerator.h"
#include <time.h>

class SimpleMaze2dGenerator : public Maze2dGenerator{
public:
    SimpleMaze2dGenerator() {};
    Maze2d generate(const string &name,int rows, int cols);
    virtual ~SimpleMaze2dGenerator() {};

};


#endif //UNTITLED2_SIMPLEMAZE2DGENERATOR_H