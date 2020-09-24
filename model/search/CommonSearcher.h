//
// Created by חן גוטמן on 20/08/2020.
//

#ifndef UNTITLED2_COMMONSEARCHER_H
#define UNTITLED2_COMMONSEARCHER_H

#pragma once
#include "Searcher.h"
#include <queue>

using namespace std;

class CommonSearcher : public Searcher
{
public:
    CommonSearcher(): m_evaluatedNodes(0){}
    virtual Solution search(Searchable& s) = 0;
    virtual int getNumberOfNodesEvaluated() { return m_evaluatedNodes; };
    const State& popOpenList() {
        m_evaluatedNodes++;
        State* state =&(m_openList.front());
       m_openList.pop();
        return *state;
    }


protected:
    int m_evaluatedNodes;
    queue<State> m_openList;
};



#endif //UNTITLED2_COMMONSEARCHER_H
