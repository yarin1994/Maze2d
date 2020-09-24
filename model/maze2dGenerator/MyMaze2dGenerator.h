

#ifndef UNTITLED2_MYMAZE2DGENERATOR_H
#define UNTITLED2_MYMAZE2DGENERATOR_H

#include "Maze2dGenerator.h"
#include "UnionFindSet.h"
#include "Maze2d.h"

class MyMaze2dGenerator : public Maze2dGenerator {
public:
    Maze2d generate(const string &name,int rows, int cols);
};


#endif //UNTITLED2_MYMAZE2DGENERATOR_H
