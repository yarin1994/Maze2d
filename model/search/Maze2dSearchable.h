//
// Created by חן גוטמן on 20/08/2020.
//

#ifndef UNTITLED2_MAZE2DSEARCHABLE_H
#define UNTITLED2_MAZE2DSEARCHABLE_H

#pragma once
#include "Searchable.h"
#include "../maze2dGenerator/Maze2d.h"
#include "Maze2dState.h"

class Maze2dSearchable : public Searchable
{
public:
    Maze2dSearchable(Maze2d& maze): m_maze(maze){}
    virtual State& getStartState() {
        State* state = new State(m_maze.getStartPosition());
        return *state;
    }
    virtual State& getGoalState() {
        State* state = new State(m_maze.getGoalPosition());
        return *state;
    }
    virtual vector<State> getAllPossibleStates(State& s) {
        vector<State> possibleStates;
        int row= s.getStatePosition().getRowIndex();
        int cols= s.getStatePosition().getColumnsIndex();
        string* possibleMove= m_maze.getPossibleMoves(s.getStatePosition());
        for(int i =0;i<4;i++){
            if(possibleMove[i]=="") continue;
            if(possibleMove[i]=="Up"){
                Position *p =new Position(row-1,cols);
                State up = State(*p, s.getCost() + 1, &s);
                possibleStates.push_back(up);
            }
            if(possibleMove[i]=="Down"){
                Position *p = new Position(row+1,cols);
                State down = State(*p, s.getCost() + 1, &s);
                possibleStates.push_back(down);
            }
            if(possibleMove[i]=="Right"){
                Position *p = new Position(row,cols+1);
                State right = State(*p, s.getCost() + 1, &s);
                possibleStates.push_back(right);
            }
            if(possibleMove[i]=="Left"){
                Position* p = new Position(row,cols-1);
                State left = State(*p, s.getCost() + 1, &s);
                possibleStates.push_back(left);
            }
        }
        return possibleStates;
    };
    virtual void setCurrentPosition(int r, int c){
        m_maze.setCurrentPostion(r,c);
    }
    virtual State& getCurrentState(){
        State* state = new State (m_maze.getCurrentPosition());
        return *state;
    }


private:
    Maze2d m_maze;
};

#endif //UNTITLED2_MAZE2DSEARCHABLE_H
