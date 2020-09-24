//
// Created by חן גוטמן on 20/08/2020.
//

#ifndef UNTITLED2_SEARCHABLE_H
#define UNTITLED2_SEARCHABLE_H

#include <vector>
#include "State.h"
using namespace std;

class Searchable
{
public:
    virtual State& getStartState() = 0;
    virtual State& getGoalState() = 0;
    virtual vector<State> getAllPossibleStates(State& s) = 0;
    virtual void setCurrentPosition(int r, int c)=0;
    virtual State& getCurrentState()=0;
};

#endif //UNTITLED2_SEARCHABLE_H
