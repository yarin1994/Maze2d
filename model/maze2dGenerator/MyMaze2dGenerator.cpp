//
// Created by חן גוטמן on 12/08/2020.
//

#include "MyMaze2dGenerator.h"

Maze2d MyMaze2dGenerator::generate(const string &name,int rows, int cols) {

    Maze2d* maze = new Maze2d(name,rows, cols);
    Position** mazeBoard = maze->getMazeBoard();
    int r = rand() % rows;
    int c = rand() % rows;

    Position entrance=  Position(r,0);
    Position exit =  Position(c,cols-1);
    maze->setEntrancePosition(entrance);
    maze->setGoalPostion(exit);


    int numOfElements = ((rows * cols));
    UnionFindSet UnionFindSet(numOfElements);




    int indexCount = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mazeBoard[i][j].setIndexNumber(indexCount);
            indexCount++;
        }
    }

    for (int i = 0; i < cols; i++)
    {
        mazeBoard[0][i].setBorder(0);
    }

    for (int i = 0; i < cols; i++)
    {
        mazeBoard[(rows - 1)][i].setBorder(1);
    }
    for (int i = 0; i < rows; i++)
    {
        mazeBoard[i][(cols - 1)].setBorder(2);
    }
    for (int i = 0; i < rows; i++)
    {
        mazeBoard[i][0].setBorder(3);
    }

    srand(time(NULL));
    while (UnionFindSet.getNumOfSets() > 1)
    {

        int randRow = (rand() % rows);
        int randColumn = (rand() % cols);
        int randomWall = (rand() % 4);

        int index = mazeBoard[randRow][randColumn].getIndexNumber();

        switch (randomWall) {
            case 0: //up
                if (mazeBoard[randRow][randColumn].checkBorder(0) == false)
                {
                    if (UnionFindSet.find(index) != UnionFindSet.find((index - cols)))
                    {
                        UnionFindSet.unionSets(index, (index - cols));
                        mazeBoard[randRow][randColumn].breakWall(0);
                        mazeBoard[(randRow - 1)][randColumn].breakWall(1);
                    }
                }
                break;

            case 1: // down
                if (mazeBoard[randRow][randColumn].checkBorder(1) == false)
                {

                    if (UnionFindSet.find(index) != UnionFindSet.find((index + cols)))
                    {
                        UnionFindSet.unionSets(index, (index + cols));
                        mazeBoard[randRow][randColumn].breakWall(1);
                        mazeBoard[(randRow + 1)][randColumn].breakWall(0);
                    }

                }
                break;

            case 2: // right
                if (mazeBoard[randRow][randColumn].checkBorder(2) == false)
                {
                    if (UnionFindSet.find(index) != UnionFindSet.find((index + 1)))
                    {
                        UnionFindSet.unionSets(index, (index + 1));
                        mazeBoard[randRow][randColumn].breakWall(2);
                        mazeBoard[randRow][(randColumn + 1)].breakWall(3);
                    }
                }
                break;

            case 3: //left
                if (mazeBoard[randRow][randColumn].checkBorder(3) == false)
                {
                    if (UnionFindSet.find(index) != UnionFindSet.find((index - 1)))
                    {
                        UnionFindSet.unionSets(index, ((index - 1)));
                        mazeBoard[randRow][randColumn].breakWall(3);
                        mazeBoard[randRow][(randColumn - 1)].breakWall(2);
                    }
                }
                break;
        }

    }

    maze->setMazeBoard(mazeBoard);
    return *maze;

}
