//
// Created by חן גוטמן on 24/08/2020.
//

#ifndef UNTITLED3_CONTROLLER_H
#define UNTITLED3_CONTROLLER_H
#include "Command.h"
#include "Observer.h"
#include "../view/View.h"
#include "../model/Model.h"
#include <map>

using namespace std;

class Controller : public Observer{

public:
    virtual Command* get(const string& commnad)=0;

    // the update method are already define in Observer class.
};

#endif //UNTITLED3_CONTROLLER_H
