//
// Created by חן גוטמן on 24/08/2020.
//

#ifndef UNTITLED3_MYCONTROLLER_H
#define UNTITLED3_MYCONTROLLER_H

#include "Controller.h"
#include "../model/MyModel.h"


class MyController : public Controller{
public:
    MyController(View *v)
    {
        if (v!= nullptr){
            view=v;
        }
        model= new MyModel();
        model->addObserver(*this);

        m_commands.insert({"dir",new dirCommand(model)});
        m_commands.insert({"generate maze",new generateMazeCommand(model)});
        m_commands.insert({"display",new displayMazeCommand(model)});
        m_commands.insert({"save maze",new saveMazeCommand(model)});
        m_commands.insert({"load maze",new loadMazeCommand(model)});
        m_commands.insert({"maze size",new mazeSizeCommand(model)});
        m_commands.insert({"file size",new fileSizeCommand(model)});
        m_commands.insert({"solve",new solveCommand(model)});
        m_commands.insert({"display solution",new displaySolutionCommand(model)});
        m_commands.insert({"exit",new exitCommand()});

    }
    virtual Command* get(const string& commnad){
        auto it = m_commands.find(commnad);
        if(it == m_commands.end()){
            return nullptr;
        }
        return it->second;

}
    virtual void update(Observable& o){
        string state = o.getState();
        cout<<state<<endl;
    }
private:
    map<string, Command*> m_commands;
    MyModel *model;
    View *view;

};

#endif //UNTITLED3_MYCONTROLLER_H
