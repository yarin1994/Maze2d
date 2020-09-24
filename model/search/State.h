//
// Created by חן גוטמן on 20/08/2020.
//

#ifndef UNTITLED2_STATE_H
#define UNTITLED2_STATE_H

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "../maze2dGenerator/Position.h"

using namespace std;

class State
{
public:
    State(Position pos, double cost=0, State* cameFrom= nullptr){
        m_state=pos.toString();
        m_cost= cost;
        m_cameFrom= cameFrom;
        p=pos;
    }
    double getCost(){
        return m_cost;
    }
    void setPosition(State& state){
        p=state.getStatePosition();
    }
    string getStateString(){
        return m_state;
    }
    State* getCameFrom(){
        return m_cameFrom;
    }
    Position getStatePosition(){
        return p;
    }
    void setCameFrom(State state){
        m_cameFrom= new State(state);
    }

    double heuristicSum(State& s,double heuristic) {
        heuristic = s.m_cost+1+heuristic;
        return heuristic;
    }

public:
    bool operator == (State& s) { return m_state.compare(s.m_state) == 0; }
    bool operator != (State& s) { return m_state.compare(s.m_state) == 1; }

private:
    string				m_state;
    double				m_cost;
    State*	            m_cameFrom;
    Position            p;


};

#endif //UNTITLED2_STATE_H
