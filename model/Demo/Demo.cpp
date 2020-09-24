//
// Created by חן גוטמן on 22/08/2020.
//

#include "Demo.h"

void Demo::run() {

    Maze2d m2d;
   // SimpleMaze2dGenerator maze;
    MyMaze2dGenerator maze;
    m2d= maze.generate("chen",6,7);
    cout<<"Welcome To our UNION FIND SET Maze!"<<endl;
    cout<<m2d<<endl;

    // BFS CHECK
    Maze2dSearchable mazed (m2d);
    BestFirstSearch bfs;
    Solution sol;
    sol= bfs.search(mazed);
    cout << "BFS solution evaluated " << bfs.getNumberOfNodesEvaluated() << endl;
    // Aster CHECK manhatthan
    ManhattanDis manhattan;
    AStar astar (&manhattan);
    sol= astar.search(mazed);
    cout << "Astar Manhatthan solution evaluated " << astar.getNumberOfNodesEvaluated() << endl;
    // Aster CHECK manhatthan
    AirDistance air;
    AStar astar2(&air);
    sol= astar2.search(mazed);
    cout << "Astar AirDistance solution evaluated " << astar2.getNumberOfNodesEvaluated() << endl;

}