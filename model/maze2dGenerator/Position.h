#ifndef UNTITLED2_POSITION_H
#define UNTITLED2_POSITION_H
#include <iostream>
#include <string>

using namespace std;

class Position {
public:
    Position();
    Position(int row, int col);
    int getRowIndex() const;
    int getColumnsIndex();
    int getIndexNumber();
    void setRows(int r);
    void setCols(int c);
    void setIndexNumber(int index);
    string toString();
    void setWalls(int up,int down,int right,int left);

    bool checkBorder(int wall);
    void setBorder(int wall);
    bool checkWall(int wall);
    void breakWall(int wall);

    friend ostream& operator << (ostream& out, const Position& c);
    ~Position() {};

private:
    int rows, cols, indexNum;
    bool topBorder, bottomBorder, rightBorder, leftBorder;
    bool topWall, bottomWall, rightWall, leftWall;

};


#endif //UNTITLED2_POSITION_H
