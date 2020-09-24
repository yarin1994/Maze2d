//
// Created by חן גוטמן on 20/08/2020.
//

#ifndef UNTITLED2_BESTFIRSTSEARCH_H
#define UNTITLED2_BESTFIRSTSEARCH_H

#pragma once

#include "CommonSearcher.h"
#include <unordered_map>
#include <vector>


using namespace std;

class BestFirstSearch : public CommonSearcher
{

public:
    virtual Solution search( Searchable& s)
    {
        unordered_map<string, State> map;
        vector<State> nextMoves;
        State start = s.getStartState();
        State goal = s.getGoalState();
        m_openList.push(start);
        map.insert({start.getStateString(),start});
        State current = start;
        State tmp=State(s.getStartState().getStatePosition());
        int currentRow ,currentCol;
        int flag = false;
        while(!m_openList.empty()|| !flag){
            if(flag){
                tmp=current;
                current=popOpenList();
                current.setCameFrom(tmp);
                currentRow= current.getStatePosition().getRowIndex();
                currentCol= current.getStatePosition().getColumnsIndex();
                s.setCurrentPosition(currentRow,currentCol);
                current.setPosition(s.getCurrentState());
            }
            if(current==goal){
                break;
            }

            nextMoves = s.getAllPossibleStates(current);
            for(State move: nextMoves){
                if (!map.count(move.getStateString())){
                    map.insert({move.getStateString(),move});
                    m_openList.push(move);
                }
            }
            flag= true;
        }

        tmp = current;
        State* prev = current.getCameFrom();
        vector <State> bestPath;
        bestPath.insert(bestPath.begin(),current);
        while (prev->getCameFrom()!= nullptr){
            currentRow=tmp.getStatePosition().getRowIndex();
            currentCol=tmp.getStatePosition().getColumnsIndex();
            int prevRow=prev->getStatePosition().getRowIndex();
            int prevCol=prev->getStatePosition().getColumnsIndex();
            if(tmp.getCost()-1==prev->getCost()){
                if(currentRow-1==prevRow && currentCol==prevCol && !tmp.getStatePosition().checkWall(0)){ // if it came from up
                    tmp = *prev;
                    bestPath.insert(bestPath.begin(),*prev);

                }
                else if(currentRow+1==prevRow && currentCol==prevCol&& !tmp.getStatePosition().checkWall(1)){ // if it came from down
                    tmp = *prev;
                    bestPath.insert(bestPath.begin(),*prev);
                }
                else if(currentRow==prevRow && currentCol+1==prevCol && !tmp.getStatePosition().checkWall(2)){ // if it came from right
                    tmp = *prev;
                    bestPath.insert(bestPath.begin(),*prev);
                }
                else if(currentRow==prevRow && currentCol-1==prevCol && !tmp.getStatePosition().checkWall(3)){ // if it came from left
                    tmp = *prev;
                    bestPath.insert(bestPath.begin(),*prev);
                }
            }
            prev = prev->getCameFrom();
        }
        current=start;
        for (int i=bestPath.size()-1;i>=0;i--){
            bestPath[i].setCameFrom(bestPath[i+1]);
        }
        current = bestPath[0];

        return Solution(current);
    }
};

#endif //UNTITLED2_BESTFIRSTSEARCH_H
