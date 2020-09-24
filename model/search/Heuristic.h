//
// Created by חן גוטמן on 23/08/2020.
//

#ifndef UNTITLED3_HEURISTIC_H
#define UNTITLED3_HEURISTIC_H

#pragma once
#include <iostream>

#include "State.h"
#include <math.h>

class Heuristic {
public:
    virtual double dist(State& st, State& goal)=0;

};

#endif //UNTITLED3_HEURISTIC_H
