//
// Created by חן גוטמן on 12/08/2020.
//

#include "UnionFindSet.h"


UnionFindSet::UnionFindSet(int numElements)
{
    for (int i = 0; i < numElements; i++)
    {
        set.push_back(-1);
    }
    numOfElements = numElements;
    numOfSets = numElements;
}




void UnionFindSet::unionSets(int root1, int root2)
{
    int i = find(root1);
    int j = find(root2);

    if (set[j] < set[i])
    {
        --set[i];
        set[j] = i;
    }
    else
    {
        --set[j];
        set[i] = j;
    }
    numOfSets--;
}

int UnionFindSet::find(int x)
{

    if (set[x] < 0)
        return x;
    else
        return set[x] = find(set[x]);
}

int UnionFindSet::getNumOfSets()
{
    return numOfSets;
}

int UnionFindSet::getNumOfElements()
{
    return numOfElements;
}
