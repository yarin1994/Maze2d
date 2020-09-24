//
// Created by חן גוטמן on 23/08/2020.
//

#ifndef UNTITLED3_MAZECOMPRESSION_H
#define UNTITLED3_MAZECOMPRESSION_H

#include "Maze2d.h"
#include <vector>
#include <fstream>


using namespace std;

class MazeCompression {
public:
    MazeCompression(){};
    vector<int> compress(vector<vector<vector<char>>> data);
    vector<vector<vector<char>>> decompress( vector<int>data ,int rows,int cols);
    void writeToFile(ofstream &out,Maze2d& maze2D);
    Maze2d readFromFile(ifstream& in);
    ~MazeCompression(){};

};


#endif //UNTITLED3_MAZECOMPRESSION_H
