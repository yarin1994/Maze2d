//
// Created by חן גוטמן on 24/08/2020.
//

#ifndef UNTITLED3_OBSERVABLE_H
#define UNTITLED3_OBSERVABLE_H
#include "../controller/Observer.h"
#include <vector>
#include <string>

using namespace std;

class Observable{
public:
    void addObserver(Observer& observer){
        _observers.push_back(&observer);
    };
    void notify(){
        for(auto it = _observers.begin(); it != _observers.end(); it++){
            (*it)->update(*this);
        }
    }
    void setState(string state){
        _stateNotice= state;
    }
    string getState(){
        return _stateNotice;
    }
private:
    vector<Observer*> _observers;
    string _stateNotice;
};

#endif //UNTITLED3_OBSERVABLE_H
