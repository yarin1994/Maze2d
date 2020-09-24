#ifndef UNTITLED2_MAZE2D_H
#define UNTITLED2_MAZE2D_H

#include <iostream>
#include <string>
#include <vector>
#include "Position.h"

using namespace std;

class Maze2d {
public:
    Maze2d();
    Maze2d(const string &name,int row, int col);
    Maze2d (string name,int _rows,int _cols,Position start,Position goal,vector<vector<vector<char>>> _data);


    void setEntrancePosition(Position start);
    void setGoalPostion(Position goal);
    void setCurrentPostion(int r,int c);
    void setMazeBoard(Position** board);
    void setName(const string &name);
    string* getPossibleMoves(Position p);
    string getName();

    Position getStartPosition();
    Position getGoalPosition();
    Position getCurrentPosition();
    Position** getMazeBoard();

    vector<vector<vector<char>>> getData();
    void fromPositionToBinary(const Maze2d& maze);
    void setData(vector<vector<vector<char>>> data);
    Position** fromBinaryToPosition(vector<vector<vector<char>>> data,int row,int col);

    friend ostream& operator << (ostream& out, const Maze2d& maze);

    ~Maze2d() {};



private:
    vector<vector<vector<char>>> data;
    Position** mazeBoard;
    Position entry, exit ,currPos;
    int rows, cols;
    string _name;


    void setData(vector<vector<string>> data);
};


#endif //UNTITLED2_MAZE2D_H


