//
// Created by חן גוטמן on 25/08/2020.
//

#ifndef UNTITLED3_AIRDISTANCE_H
#define UNTITLED3_AIRDISTANCE_H

#include "Heuristic.h"

using namespace std;

class AirDistance: public Heuristic{
public:
    virtual double dist(State& st, State& goal){
        double row = abs(st.getStatePosition().getRowIndex()-goal.getStatePosition().getRowIndex());
        double col = abs(st.getStatePosition().getColumnsIndex()-goal.getStatePosition().getColumnsIndex());
        double root = sqrt((row*row)+(col*col));
        double sum = abs(st.getCost()-st.getCameFrom()->getCost());

        return (root * sum);
    }
};

#endif //UNTITLED3_AIRDISTANCE_H
