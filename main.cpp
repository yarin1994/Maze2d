#include <iostream>
#include <string>
#include <fstream>
#include "model/Demo/Demo.h"
#include "model/maze2dGenerator/MazeCompression.h"
#include "view/CLI.h"



using namespace std;

class TestMazeGenerator
{
public:
    TestMazeGenerator() {};
    void testMazeGenerator(Maze2dGenerator & mg)
    {
        cout << mg.measureAlgorithmTime("chen",6, 6) << endl;

        Maze2d maze = mg.generate("chen",8,8);

        Position p = maze.getStartPosition();

        cout << p << endl;

        string* moves= maze.getPossibleMoves(p);
        for(int i=0;i<4;i++){
            if(moves[i]=="") continue;
            else cout<<moves[i]<<endl;
        }
        cout<<maze.getGoalPosition()<<endl;

        cout<<maze<<endl;

    }
};


int main() {

//    Demo demo;
//    demo.run();

CLI *cli= new CLI(cout,cin);
cli->start();

    return 0;
}
