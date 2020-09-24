//
// Created by חן גוטמן on 24/08/2020.
//

#ifndef UNTITLED3_OBSERVER_H
#define UNTITLED3_OBSERVER_H

using namespace std;
class Observable;

class Observer{
public:
    virtual void update(Observable& o)=0;
};

#endif //UNTITLED3_OBSERVER_H
