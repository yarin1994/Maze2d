//
// Created by חן גוטמן on 23/08/2020.
//

#ifndef UNTITLED3_ASTAR_H
#define UNTITLED3_ASTAR_H

#include "CommonSearcher.h"
#include "Heuristic.h"
#include <unordered_map>
#include <vector>

using namespace std;

class AStar : public CommonSearcher{
private:
    Heuristic* _h;
public:
    AStar(Heuristic* h){
        _h=h;
    }
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
        State* split;
        vector<State> splits;
        State* it;
        int currentRow ,currentCol,tmpRow,tmpCol;

        double heuristicCurrCheck,heuristicNextCheck;
        while(!m_openList.empty()){
            if(m_openList.size()==1){
                tmp=current;
                current=popOpenList();
                current.setCameFrom(tmp);
                currentRow= current.getStatePosition().getRowIndex();
                currentCol= current.getStatePosition().getColumnsIndex();
                s.setCurrentPosition(currentRow,currentCol);
                current.setPosition(s.getCurrentState());
            }
            else{
                tmp=current;
                current=popOpenList();
                current.setCameFrom(tmp);
                currentRow= current.getStatePosition().getRowIndex();
                currentCol= current.getStatePosition().getColumnsIndex();
                split=&m_openList.front();
                split->setCameFrom(tmp);
                splits.push_back(*split);
                heuristicCurrCheck= current.heuristicSum(current,_h->dist(current,goal));
                heuristicNextCheck= current.heuristicSum(*split,_h->dist(*split,goal));
                if(heuristicCurrCheck<=heuristicNextCheck){
                    splits.push_back(*split);
                    m_openList.pop();
                    s.setCurrentPosition(currentRow,currentCol);
                    current.setPosition(s.getCurrentState());
                }
                else{
                    splits.push_back(current);
                    tmp=*current.getCameFrom();
                    m_evaluatedNodes--;
                    current=popOpenList();
                    current.setCameFrom(tmp);
                    currentRow= current.getStatePosition().getRowIndex();
                    currentCol= current.getStatePosition().getColumnsIndex();
                    s.setCurrentPosition(currentRow,currentCol);
                    current.setPosition(s.getCurrentState());
                }
            }

            if(current==goal){
                break;
            }
            if(splits.size()>0 ){
                tmpRow = tmp.getStatePosition().getRowIndex();
                tmpCol= tmp.getStatePosition().getColumnsIndex();
                if(currentRow-1==tmpRow){ // came from up
                    if(current.getStatePosition().checkWall(1)&&current.getStatePosition().checkWall(2)&&current.getStatePosition().checkWall(3)){
                        int size= splits.size()-1;
                        it = &splits[size];
                        current=*it;
                    }
                }
                else if(currentRow+1==tmpRow){ // came from down
                    if(current.getStatePosition().checkWall(0)&&current.getStatePosition().checkWall(2)&&current.getStatePosition().checkWall(3)){
                        int size= splits.size()-1;
                        it = &splits[size];
                        current=*it;
                    }
                }
                else if(currentCol-1==tmpCol){ // came from right
                    if(current.getStatePosition().checkWall(0)&&current.getStatePosition().checkWall(1)&&current.getStatePosition().checkWall(3)){
                        int size= splits.size()-1;
                        it = &splits[size];
                        current=*it;
                    }
                }
                else if(currentCol-1==tmpCol){ // came from left
                    if(current.getStatePosition().checkWall(0)&&current.getStatePosition().checkWall(1)&&current.getStatePosition().checkWall(2)){
                        int size= splits.size()-1;
                        it = &splits[size];
                        current=*it;
                    }
                }
            }

            nextMoves = s.getAllPossibleStates(current);
            for(int i=0;i<nextMoves.size();i++){
                if (!map.count(nextMoves[i].getStateString())){
                    map.insert({nextMoves[i].getStateString(),nextMoves[i]});
                    m_openList.push(nextMoves[i]);
                }
            }
        }



        return Solution(current);
    }
};
#endif //UNTITLED3_ASTAR_H
