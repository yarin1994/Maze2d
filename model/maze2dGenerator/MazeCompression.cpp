//
// Created by חן גוטמן on 23/08/2020.
//

#include "MazeCompression.h"

vector<int> MazeCompression:: compress(vector<vector<vector<char>>> data){
    vector<int> compression;
    vector<int> compreesed;
    int counter=1,rows,cols;
    rows = data.size();
    cols = data[0].size();
    int size=0;
    for(int i=0;i<rows;i++){
        compression.resize(size+4);
        for(int j=0;j<cols;j++){
            compression[size]=(int)data[i][j][0];
            compression[size+1]=(int)data[i][j][1];
            compression[size+2]=(int)data[i][j][2];
            compression[size+3]=(int)data[i][j][3];
            size+=4;
            if(j!=cols-1){
                compression.resize(size+4);
            }
        }
    }

    for(int i=0;i<size;i++){
        if(compression[i]==compression[i+1]){
            counter++;
        }
        else{
//            compreesed.resize(2);
            compreesed.push_back(compression[i]);
            compreesed.push_back(counter);
            counter =1;
        }
    }
    return compreesed;

}
vector<vector<vector<char>>> MazeCompression::  decompress( vector<int>data ,int rows,int cols){
    vector<vector<vector<char>>> _data;
    vector<int> decompressData;
    int size = 0,counter,value;
    for(int i=0;i<data.size();i+=2){
        value=data[i];
        counter = data[i+1];
        while (counter>0){
            decompressData.push_back(value);
            counter--;
        }
    }

    _data.resize(rows);
    for(int i =0 ; i<rows;i++){
        _data[i].resize(cols);
        for(int j=0 ; j<cols ; j++){
            _data[i][j].resize(4);
            _data[i][j][0]= (char)decompressData[size];
            _data[i][j][1]=(char)decompressData[size+1];
            _data[i][j][2]= (char)decompressData[size+2];
            _data[i][j][3]=(char)decompressData[size+3];
            size+=4;
        }
    }
    return _data;
}
void MazeCompression::  writeToFile(ofstream &out,Maze2d& maze2D){
    Maze2d maze;
    maze.fromPositionToBinary(maze2D);
    maze2D.setData(maze.getData());

    int name = maze2D.getName().length();
    const char* _name = maze2D.getName().c_str();
    int start_row = maze2D.getStartPosition().getRowIndex();
    int start_col = maze2D.getStartPosition().getColumnsIndex();
    int goal_row = maze2D.getGoalPosition().getRowIndex();
    int goal_col = maze2D.getGoalPosition().getColumnsIndex();
    int rows = maze2D.getData().size();
    int cols = maze2D.getData()[1].size();

    auto m2d = compress(maze2D.getData());

    out<<_name<<endl<<start_row<<endl<<start_col<<endl<<goal_row<<endl<<goal_col<<endl<<rows<<endl<<cols<<endl;

    for(int i=0;i<m2d.size();i++){
        out<<m2d[i];
    }
//    out.write((char*)&name, sizeof(name));
//    out.write(_name,name);
//    out.write((char*)&rows, sizeof(rows));
//    out.write((char*)&cols, sizeof(cols));
//    out.write((char*)&start_row, sizeof(start_row));
//    out.write((char*)&start_col, sizeof(start_col));
//    out.write((char*)&goal_row, sizeof(goal_row));
//    out.write((char*)&goal_col, sizeof(goal_col));


//    out.write((char*)&m2d[0],m2d.size()* sizeof(char*)); // to check

}
Maze2d MazeCompression::  readFromFile(ifstream& in){
 string name;
 string rows, cols,start_row, start_col, goal_row, goal_col;
 int _rows, _cols,_start_row, _start_col, _goal_row, _goal_col;
 string data;
 vector<int>_data;


// in.read((char*)&_name, sizeof(_name));
// if(_name != 0){
//     name = new char[_name+1];
//     in.read(name, _name);
//     name[_name] = '\0';
// }
 if(in.is_open()){

     getline(in,name);
     getline(in,start_row);
     getline(in,start_col);
     getline(in,goal_row);
     getline(in,goal_col);
     getline(in,rows);
     getline(in,cols);
     getline(in,data);
 }
  _start_row=stoi(start_row);
    _start_col=stoi(start_col);
    _goal_row=stoi(goal_row);
    _goal_col=stoi(goal_col);
    _rows=stoi(rows);
    _cols=stoi(cols);

    for(int i=0;i<data.length();i++){
        _data.push_back(data[i]-'0');
    }



// in.read((char*)&start_row, sizeof(start_row));
// in.read((char*)&start_col, sizeof(start_col));
// in.read((char*)&goal_row, sizeof(goal_col));
// in.read((char*)&goal_col, sizeof(start_col));
// in.read((char*)&rows, sizeof(rows));
// in.read((char*)&cols, sizeof(cols));


// string m_name(name);
// delete name;

// int temp;
// while (in.read((char*)&temp, sizeof(temp))){
//
//     _data.push_back(temp);
// }

 auto dataa = decompress(_data, _rows, _cols);
 return Maze2d(name, _rows, _cols,Position(_start_row,_start_col),Position(_goal_row,_goal_col),dataa);

}