//
// Created by חן גוטמן on 12/08/2020.
//


#ifndef UNTITLED2_UNIONFINDSET_H
#define UNTITLED2_UNIONFINDSET_H

//union find set to build a maze

#include "Maze2d.h"
#include <vector>
using namespace std;


class UnionFindSet {
public:
    UnionFindSet() {};
    UnionFindSet(int numElements);
    int find(int x);
    void unionSets(int root1, int root2);
    int getNumOfSets();
    int getNumOfElements();
    virtual ~UnionFindSet() {};

private:
    vector<int> set;
    int numOfSets;
    int numOfElements;
};


#endif //UNTITLED2_UNIONFINDSET_H
