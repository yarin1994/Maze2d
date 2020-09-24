//
// Created by חן גוטמן on 24/08/2020.
//

#ifndef UNTITLED3_COMMAND_H
#define UNTITLED3_COMMAND_H
#include <iostream>
#include <string>
#include "../model/MyModel.h"
#include "../view/View.h"
#include <ostream>
#include <dirent.h>
#include <fstream>

using namespace std;

class Command {

public:
    virtual void execute() { };
    virtual void doCommand(vector<string>::iterator begin , vector<string>::iterator end) {};
};

class dirCommand : public Command {

public:
    dirCommand(MyModel* md):model(md){};
    virtual void execute() {
        struct dirent *entry;
        DIR* dir = opendir(path.c_str());

        if (dir == NULL) {
            return;
        }
        while ((entry = readdir(dir)) != NULL) {
            cout << entry->d_name << endl;
        }
        closedir(dir);

    }
    void doCommand(vector<string>::iterator begin , vector<string>::iterator end){
        if(begin!=end){
            path = *(begin);

        }
    }
    ~dirCommand(){};
private:
    //char* path;
    string dir,path;
    MyModel* model;
};
class generateMazeCommand : public Command {
public:

generateMazeCommand(MyModel *md):model(md){};
    virtual void execute() {
        if(alg=="Simple"){
            model->generateSimpleMaze(name,rows,cols);
        }
        else if( alg=="UnionFindSet"){
            model->generateAlgoMaze(name,rows,cols);
        }
        else{ //defult
            model->generateAlgoMaze(name,rows,cols);
        }
    }
    void doCommand(vector<string>::iterator begin , vector<string>::iterator end){
        if(begin!=end){
            name=*begin;
            rows= stoi(*(begin+1));
            cols= stoi(*(begin+2));
            alg = *(begin+3);
        }
    }
private:
    MyModel* model;
    string name;
    int rows;
    int cols;
    string alg;


};
class displayMazeCommand : public Command {
public:
    displayMazeCommand(MyModel *md):model(md){};
    virtual void execute() {
        model->getMaze(name);
    }
    void doCommand(vector<string>::iterator begin , vector<string>::iterator end){
        if(begin!=end){
            name=*begin;
        }
    }
private:
    string name;
    MyModel* model;
};
class saveMazeCommand : public Command {
public:
    saveMazeCommand(MyModel *md):model(md){};
    virtual void execute() {
        ofstream file;
        model->saveMaze(&file,name);

    }
    void doCommand(vector<string>::iterator begin , vector<string>::iterator end){
        if(begin!=end){
            name=*begin;
            outputFile= *(begin+1);
        }
    }
private:
    string name, outputFile;
    MyModel* model;
};
class loadMazeCommand : public Command {
public:
    loadMazeCommand(MyModel* md):model(md){};
    virtual void execute() {
        ifstream file;
        model->loadMaze(&file,name);
    }
    void doCommand(vector<string>::iterator begin , vector<string>::iterator end){
        if(begin!=end){
            name=*begin;
        }
    }
private:
    string name;
    MyModel* model;

};
class mazeSizeCommand : public Command {
public:
    mazeSizeCommand(MyModel* md):model(md){};
    virtual void execute() {
        model->getSizeMaze(name);
    }
    void doCommand(vector<string>::iterator begin , vector<string>::iterator end){
        if(begin!=end){
            name=*begin;
        }
    }
private:
    string name;
    MyModel* model;
};
class fileSizeCommand : public Command {
public:
    fileSizeCommand(MyModel* md):model(md){};
    virtual void execute() {
        model->getFileSize(name);
    }
    void doCommand(vector<string>::iterator begin , vector<string>::iterator end){
        if(begin!=end){
            name=*begin;
        }
    }
private:
    string name;
    MyModel* model;

};
class solveCommand : public Command {
public:
    solveCommand(MyModel* md):model(md){};
    virtual void execute() {
       if( alg=="Astar") {
            model->solveAstarMaze(name,alg,astarType);
        }
       else{
           model->solveBFSMaze(name,alg);
       }


    }
    void doCommand(vector<string>::iterator begin , vector<string>::iterator end){
        if(begin!=end){
            name=*begin;
            alg= *(begin +1);
            astarType = *(begin+2);

        }
    }

private:
    string name;
    MyModel* model;
    string alg, astarType;

};
class displaySolutionCommand : public Command {
public:
    displaySolutionCommand(MyModel* md):model(md){};
    virtual void execute() {
         model->displaySolution(name,alg);
    }
    void doCommand(vector<string>::iterator begin , vector<string>::iterator end){
        if(begin!=end){
            name=*begin;
            alg=*(begin+1);
        }
    }

private:
    string name;
    MyModel* model;
    string alg;
};
class exitCommand : public Command {
public:
    exitCommand(){};
    virtual void execute() {
        cout << "Thank you for using our Maze Generator"<<endl<<"Chen Gutman & Yarin Mizrahi";
        exit(0);
    }
    void doCommand(vector<string>::iterator begin , vector<string>::iterator end){
        if(begin!=end){
            name=*begin;
        }
    }

private:
    string name;
};




#endif //UNTITLED3_COMMAND_H
