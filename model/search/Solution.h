#ifndef UNTITLED2_SOLUTION_H
#define UNTITLED2_SOLUTION_H

#pragma once
#include <iostream>
#include <vector>
#include "State.h"

class Solution
{
public:
    Solution() {};
    Solution(State goal) {
        setSolution(goal);
    };
    void setSolution(State goal) {
        vector<State*>path;
        State* current;
        current =&goal;
        while (current->getCameFrom() != nullptr) {
            path.push_back(current);
            current = current->getCameFrom();
        }
        m_solution= path;

    };
    vector<State*> getMSolution(){
        return m_solution;
    }
    void printSolution(){
        for (int i = 1; i < m_solution.size()-1; i++) {
            cout <<"Cell values:" <<m_solution[i]->getStatePosition().toString() <<", cost:"<<m_solution[i]->getCost()<<endl;
        }
    }
    ~Solution() {};
private:
    vector<State*> m_solution;
};

#endif //UNTITLED2_SOLUTION_H