//
// Created by חן גוטמן on 24/08/2020.
//

#ifndef UNTITLED3_CLI_H
#define UNTITLED3_CLI_H

#include <iostream>
#include <string>
#include <sstream>
#include "View.h"
#include "../controller/Command.h"
#include "../controller/MyController.h"
#include <unordered_map>

using namespace std;
class CLI : public View {
public:
    CLI (): out(cout), in(cin){};
    CLI (ostream &m_out,istream &m_in): out(m_out),in(m_in){}
    vector <string> infoInput(string s){
        stringstream convertFromUser(s);
        vector<string> commandInfo;

        do{
            string str;
            convertFromUser>> str;
            commandInfo.push_back(str);
        }while(convertFromUser);

        return commandInfo;
    }
    virtual void start(){
        MyController *controller=new MyController(this);
        string cmd = "";
        int size=0;

        out<<"Welcome to our Maze Generator!"<<endl<<"Please enter a command:"<<endl;
        while(cmd.compare("exit")!=0){
            out<<">>";
            getline(in,cmd);
            auto CommandCheck= infoInput(cmd);
            Command* command = controller->get(CommandCheck[0]+" "+CommandCheck[1]);

            if(command!= nullptr){

                size=2;
            }
            else{
                command = controller->get(CommandCheck[0]);
                size=1;
            }
            if(command!= nullptr){
                command->doCommand(CommandCheck.begin()+size,CommandCheck.end());
                command->execute();
            }
            else{
                out<<"Wrong Command"<<endl;
            }

        }
    };

    ~CLI(){}

private:
    ostream &out;
    istream &in;
    unordered_map<string,Command> map;


};


#endif //UNTITLED3_CLI_H
