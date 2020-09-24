//
// Created by חן גוטמן on 20/08/2020.
//

#ifndef UNTITLED2_SEARCHER_H
#define UNTITLED2_SEARCHER_H

#pragma once

#include "Solution.h"
#include "Searchable.h"

class Searcher
{
public:
    virtual Solution search(Searchable& s) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
};


#endif //UNTITLED2_SEARCHER_H
