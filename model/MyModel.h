//
// Created by חן גוטמן on 24/08/2020.
//

#ifndef UNTITLED3_MYMODEL_H
#define UNTITLED3_MYMODEL_H

#include "Model.h"
#include <unordered_map>

using namespace std;

class MyModel: public Model{
private:
    unordered_map<string,Solution*> solutions;
    unordered_map<string,Maze2d*> allMazes;
    string _stateNotice;

public:
    MyModel(){};
    virtual void generateAlgoMaze(string name, int rows , int cols){
        MyMaze2dGenerator maze2d;
        Maze2d* maze = new Maze2d(maze2d.generate(name,rows,cols));
        allMazes.insert({name,maze});

        _stateNotice = "Algorithm Maze was generated successfully";
        setState(_stateNotice);
        notify();
    }
    virtual void generateSimpleMaze(string name, int rows , int cols){
        SimpleMaze2dGenerator maze2d;
        Maze2d* maze = new Maze2d(maze2d.generate(name,rows,cols));
        allMazes.insert({name,maze});

        _stateNotice = " Simple Maze was generated successfully ";
        setState(_stateNotice);
        notify();
    }
    virtual void getMaze(string name) {
        Maze2d *maze;
        auto iterator = allMazes.find(name);
        if(iterator!=allMazes.end()) {
            cout<<*iterator->second;
        }
        else{
            _stateNotice = " We couldn't find a maze named "+name;
            setState(_stateNotice);
            notify();
        }

    }
    virtual void saveMaze(ofstream *output,string name) {
        auto iterator = allMazes.find(name);
        if(iterator!=allMazes.end()) {
            if(output!= nullptr)
            {
                auto itSolution = solutions.find(name);
                if(itSolution==solutions.end()){
                    int n=0;
                    output->write((char*)&n,sizeof(int));
                }
                output->open(name+".txt");
                MazeCompression mazeComp;
                mazeComp.writeToFile(*output,*(iterator->second));
                output->close();
                _stateNotice = " Maze writen to file successfully";
                setState(_stateNotice);
                notify();
            }
            else{
                _stateNotice = " ERROR, Cannot open this file!";
                setState(_stateNotice);
                notify();
            }
        }
        else{
            _stateNotice = " We couldn't find a maze named "+name;
            setState(_stateNotice);
            notify();
        }
    }
    virtual void loadMaze(ifstream *input,string name) {
        if(input!=NULL){
            MazeCompression maze_comp;
            Solution solution;
            int size=0;
            input->open(name+".txt");
            input->read((char*)&size,sizeof(size));
            allMazes[name]=new Maze2d(maze_comp.readFromFile(*input));
            _stateNotice = " Maze was loaded successfully ";
            setState(_stateNotice);
            notify();
        }
        else {
            _stateNotice = " We couldn't find a maze named "+name;
            setState(_stateNotice);
            notify();
        }
    }
    virtual void getSizeMaze(string name) {
        auto iterator = allMazes.find(name);
        if(iterator == allMazes.end()){
            _stateNotice = " We couldn't find a maze named "+name;
            setState(_stateNotice);
            notify();
        }
        else{
            _stateNotice = " The maze size is: " +to_string(sizeof(*iterator->second));
            setState(_stateNotice);
            notify();
        }


    }
    virtual void getFileSize(string name) {
        FILE *p_file = NULL;
        p_file = fopen(name.c_str(),"rb");
        fseek(p_file,0,SEEK_END);
        int size = ftell(p_file);
        fclose(p_file);
        _stateNotice = " The maze size is: " +to_string(size);
        setState(_stateNotice);
        notify();
    }
    virtual void solveBFSMaze(string name,string alg) {
        auto iterator = allMazes.find(name);
        if (iterator == allMazes.end()){
            _stateNotice = " We couldn't find a maze named "+name;
            setState(_stateNotice);
            notify();
            return;
        }
        auto algorithm_solutions = solutions.find(name);
        if(algorithm_solutions == solutions.end()){
            Maze2dSearchable mazeSearch(*iterator->second);
            if( "BFS" == alg){
                BestFirstSearch BFS;
                Solution sol;
                sol = BFS.search(mazeSearch);
                solutions[name+alg]=&sol;
                string str=to_string(BFS.getNumberOfNodesEvaluated());
                _stateNotice = " Maze was Solved! the evaluated number is:"+str;
                setState(_stateNotice);
                notify();
            }
            else{
                _stateNotice = " We couldn't find this algorithm";
                setState(_stateNotice);
                notify();
            }

        }

    }
    virtual void solveAstarMaze(string name,string alg,string astarType) {
        auto iterator = allMazes.find(name);
        if (iterator == allMazes.end()){
            _stateNotice = " We couldn't find a maze named "+name;
            setState(_stateNotice);
            notify();
            return;
        }
        auto algorithm_solutions = solutions.find(name);
        if(algorithm_solutions == solutions.end()){
            Maze2dSearchable mazeSearch(*iterator->second);
            if( astarType == "Manhattan"){
                ManhattanDis manhattan;
                AStar astar (&manhattan);
                Solution sol;
                sol= astar.search(mazeSearch);
                solutions[name+alg]=&sol;
                string str=to_string(astar.getNumberOfNodesEvaluated());
                _stateNotice = " Maze was Solved! the evaluated number is:"+str;
                setState(_stateNotice);
                notify();
            }
            else if(astarType == "AirDistance"){
                AirDistance air;
                AStar astar(&air);
                Solution sol;
                sol= astar.search(mazeSearch);
                solutions[name+alg]=&sol;
                string str=to_string(astar.getNumberOfNodesEvaluated());
                _stateNotice = " Maze was Solved! the evaluated number is:"+str;
                setState(_stateNotice);
                notify();
            }
            else{
                _stateNotice = " We couldn't find this algorithm";
                setState(_stateNotice);
                notify();
            }

        }

    }
    virtual void displaySolution(string name,string alg) {
        auto iterator = allMazes.find(name);
        auto iterator_sol = solutions.find(name+alg);
        Solution sol;

        if(iterator == allMazes.end()){
            _stateNotice = " We couldn't find a maze named "+name;
            setState(_stateNotice);
            notify();
        }

        else if(iterator_sol == solutions.end()){
            _stateNotice = " We couldn't find a solution for this maze";
            setState(_stateNotice);
            notify();
        }
        else{
            Maze2dSearchable mazeSearch(*iterator->second);
            Solution sol;
            if(alg=="Astar"){
                ManhattanDis manhatthan;
                AStar aStar(&manhatthan);
                sol = aStar.search(mazeSearch);
                sol.printSolution();
            }
            else{
                BestFirstSearch BFS;
                sol = BFS.search(mazeSearch);
                sol.printSolution();
            }

        }

    }
    ~MyModel(){
        allMazes.clear();
        solutions.clear();
    };

};

#endif //UNTITLED3_MYMODEL_H
