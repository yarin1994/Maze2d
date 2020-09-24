//
// Created by חן גוטמן on 20/08/2020.
//

#ifndef UNTITLED2_MAZE2DSTATE_H
#define UNTITLED2_MAZE2DSTATE_H

#pragma once
#include "State.h"
#include "../maze2dGenerator/Maze2d.h"


class Maze2dState : public State
{
public:
    Maze2dState(Position pos, double cost=0, State* cameFrom= nullptr) : State(pos,cost,cameFrom) {
        p=pos;
    };
    Position getPosition(int r , int c){
        maze.setCurrentPostion(r,c);
        return maze.getCurrentPosition();
    };
    Position getStatePosition(){
        return p;
    }

private:
    Position p;
    Maze2d maze;
};

#endif //UNTITLED2_MAZE2DSTATE_H
