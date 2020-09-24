#include "Maze2d.h"


Maze2d::Maze2d() {}

Maze2d::Maze2d(const string &name,int row, int col) {
    rows = row;
    cols = col;
    _name = name;
    mazeBoard = new Position * [rows];
    for (int i = 0; i < rows; i++) {
        mazeBoard[i] = new Position[cols];
    }

}
Maze2d ::Maze2d (string name,int _rows,int _cols,Position start,Position goal,vector<vector<vector<char>>> _data){
    data= _data;
    rows=_rows;
    cols=_cols;
    entry=start;
    exit= goal;
    _name=name;
    mazeBoard=fromBinaryToPosition(data,rows,cols);
}
Position** Maze2d::getMazeBoard(){
    return mazeBoard;
}
vector<vector<vector<char>>> Maze2d:: getData(){
    return data;
}

string Maze2d:: getName(){
    return _name;
}
Position Maze2d::getStartPosition() {
    return entry;
}

Position Maze2d::getGoalPosition() {
    return exit;
}
ostream& operator << (ostream& out, const Maze2d& maze)
{
    int entranceRow = maze.entry.getRowIndex();
    int exitRow = maze.exit.getRowIndex();
    for (int i = 0; i < maze.cols; i++) {
        out << " _";
    }
    out << endl;
    for (int i = 0; i < maze.rows; i++) {
        if (entranceRow != i) out << "|";
        else out << " ";
        for (int j = 0; j < maze.cols; j++) {
            if (j > 0) {
                if (maze.mazeBoard[i][j].checkWall(3) || maze.mazeBoard[i][j - 1].checkWall(2)) {
                    cout << "|";
                }
                else out << " ";

            }
            if (maze.mazeBoard[i][j].checkWall(1) || maze.mazeBoard[i + 1][j].checkWall(0))
                out << "_";
            else out << " ";
            if (exitRow == i && j == maze.cols - 1) out << " ";
            else if (exitRow != i && j == maze.cols - 1)
                out << "|";
        }
        out << endl;

    }
//    for (int i=0;i<maze.rows;i++){
//        for(int j =0;j<maze.cols;j++){
//            out<<maze.mazeBoard[i][j].checkWall(0)<<maze.mazeBoard[i][j].checkWall(1)<<maze.mazeBoard[i][j].checkWall(2)<<maze.mazeBoard[i][j].checkWall(3)<<endl;
//        }
//    }
    return out;
}


void Maze2d::setEntrancePosition(Position start) {
    entry = start;
}
void Maze2d::setCurrentPostion(int r,int c){
    currPos = mazeBoard[r][c];
    currPos.setRows(r);
    currPos.setCols(c);
}

void Maze2d::setGoalPostion(Position goal) {
    exit = goal;
}

void Maze2d::setMazeBoard(Position** board) {
    mazeBoard = board;
}

string* Maze2d::getPossibleMoves(Position p ) {
    int counter=1;
    string* possibleMoves= new string [4];

    int r= p.getRowIndex();
    int c = p.getColumnsIndex();
    if (r!=0 && !mazeBoard[r][c].checkWall(0)) {
        possibleMoves[counter-1] = "Up";
        counter++;
        possibleMoves->resize(counter);
    }
    if (r!=rows-1 && !mazeBoard[r][c].checkWall(1)) {
        possibleMoves[counter-1] = "Down";
        counter++;
    }
    if (c!=cols-1 && !mazeBoard[r][c].checkWall(2)) {
        possibleMoves[counter-1] = "Right";
        counter++;
    }
    if (c!=0 && !mazeBoard[r][c].checkWall(3) ) {
        possibleMoves[counter-1] = "Left";
    }

    return possibleMoves;
}

Position Maze2d:: getCurrentPosition(){
    return currPos;
}

void Maze2d::fromPositionToBinary(const Maze2d& maze){
    vector<vector<vector<char>>> _data;
    _data.resize(maze.rows);
    for (int i=0;i<maze.rows;i++){
        _data[i].resize(maze.cols);
        for(int j =0;j<maze.cols;j++) {
            _data[i][j].resize(4);
        }
    }

    for (int i=0;i<maze.rows;i++){
        for(int j =0;j<maze.cols;j++){
            _data[i][j][0] = maze.mazeBoard[i][j].checkWall(0);
            _data[i][j][1] = maze.mazeBoard[i][j].checkWall(1);
            _data[i][j][2]= maze.mazeBoard[i][j].checkWall(2);
            _data[i][j][3]= maze.mazeBoard[i][j].checkWall(3);
        }
    }
    data=_data;
}

Position** Maze2d:: fromBinaryToPosition(vector<vector<vector<char>>> _data,int row,int col){
    Position** mazeBoardFromFile ;
    mazeBoardFromFile = new Position * [row];
    for (int i = 0; i < row; i++) {
        mazeBoardFromFile[i] = new Position[col];
    }
    for (int i=0;i<row;i++){
        mazeBoardFromFile[i]=new Position();
        for(int j =0;j<col;j++){
            mazeBoardFromFile[i][j].setWalls(_data[i][j][0],_data[i][j][1],_data[i][j][2],_data[i][j][3] );
        }
    }
    return mazeBoardFromFile;
}
void Maze2d::setData(vector<vector<vector<char>>> _data) {
    data=_data;
}
void Maze2d:: setName(const string &name){
    _name=name;
}