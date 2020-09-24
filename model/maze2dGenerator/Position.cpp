#include "Position.h"
Position::Position() {
    // all borders in cell are false by default
    topBorder = false;
    bottomBorder = false;
    leftBorder = false;
    rightBorder = false;
    // all walls in cell are true by default
    topWall = true;
    bottomWall = true;
    leftWall = true;
    rightWall = true;
}

Position::Position(int row, int col) {
    rows = row;
    cols = col;

};

int Position::getRowIndex() const {
    return rows;
};
int Position::getColumnsIndex() {
    return cols;
};
void Position:: setRows(int r){
    rows= r;
}
void Position:: setCols(int c){
    cols =c;
}
void Position::breakWall(int wall)
{
    switch (wall) {
        case 0: topWall = false;
            return;
        case 1: bottomWall = false;
            return;
        case 2: rightWall = false;
            return;
        case 3: leftWall = false;
            return;
    }
}
bool Position::checkWall(int wall)
{
    switch (wall) {
        case 0: return topWall;
        case 1: return bottomWall;
        case 2: return rightWall;
        case 3: return leftWall;
    }
}

void Position::setBorder(int wall)
{
    switch (wall) {
        case 0: topBorder = true;
            break;
        case 1: bottomBorder = true;
            break;
        case 2: rightBorder = true;
            break;
        case 3: leftBorder = true;
            break;
    }
}
void Position::setIndexNumber(int index)
{
    indexNum = index;
}

int Position::getIndexNumber()
{
    return indexNum;
}


bool Position::checkBorder(int wall)
{
    switch (wall) {
        case 0: return topBorder;
        case 1: return bottomBorder;
        case 2: return rightBorder;
        case 3: return leftBorder;
    }
}
string Position:: toString(){
    string str1 = to_string(rows);
    string str2= to_string(cols);
    string str = "{"+str1 +","+str2+"}";
    return str;
}

ostream& operator << (ostream& out, const Position & p)
{
    out << "{" << p.rows<<","<<p.cols<<"}" << endl;
    return out;
}
void Position:: setWalls(int up,int down,int right,int left){
    topWall= up;
    bottomWall=down;
    rightWall=right;
    leftWall=left;
}