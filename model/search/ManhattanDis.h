//
// Created by חן גוטמן on 23/08/2020.
//

#ifndef UNTITLED3_MANHATTANDIS_H
#define UNTITLED3_MANHATTANDIS_H

#include "Heuristic.h"

using namespace std;

class ManhattanDis: public Heuristic{
public:
    virtual double dist(State& st, State& goal){
        int current_row = st.getStatePosition().getRowIndex();
        int current_col = st.getStatePosition().getColumnsIndex();
        int goal_row = goal.getStatePosition().getRowIndex();
        int goal_col = goal.getStatePosition().getColumnsIndex();

        int d_row = abs(goal_row - current_row);
        int d_col = abs(goal_col - current_col);

        return (d_row + d_col);
    }
};
#endif //UNTITLED3_MANHATTANDIS_H
