#include "SimpleMaze2dGenerator.h"

Maze2d SimpleMaze2dGenerator::generate(const string &name, int rows, int cols) {

    Maze2d* maze = new Maze2d(name,rows, cols);
    srand(time(NULL));

    int r = rand() % rows;
    int c = rand() % rows;

    Position* entrance = new Position(r, 0);
    Position* exit = new Position(c, cols - 1);
    maze->setEntrancePosition(*entrance);
    maze->setGoalPostion(*exit);

    Position** mazeBoard = new Position * [rows];
    for (int i = 0; i < rows; i++) {
        mazeBoard[i] = new Position[cols];
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
    int breakWall;
    srand(time(NULL));

    mazeBoard[r][0].breakWall(3);
    mazeBoard[c][cols - 1].breakWall(2);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == c && j == cols - 1) {
                if (i == 0) { // if the exit is in the right bottom corner
                    mazeBoard[i][j].breakWall(1);
                    if (i < rows - 1)mazeBoard[i + 1][j].breakWall(0);
                }
                else {
                    mazeBoard[i][j].breakWall(0);
                    if (i > 0)mazeBoard[i - 1][j].breakWall(1);
                    if (i < rows - 1) {
                        mazeBoard[i][j].breakWall(1);
                        mazeBoard[i + 1][j].breakWall(0);
                        mazeBoard[i][j - 1].breakWall(2);
                        mazeBoard[i][j].breakWall(3);
                    }
                }
                continue;
            }
            if (i == r && j == 0) { // if the entrance is in the left bottom corner.
                if (r == rows - 1) {
                    mazeBoard[i][j].breakWall(0);
                    mazeBoard[i-1][j].breakWall(1);
                    mazeBoard[i][j].breakWall(2);
                    mazeBoard[i][j+1].breakWall(3);
                }
            }

            breakWall = rand() % 6; // 0 or 3- two wall, 1 or 4- right wall , 2 or 5- bottom wall

            if (j > 0 && i == 0) { // if we are in the top row
                if (mazeBoard[i][j - 1].checkWall(2) == true) {
                    if (breakWall == 0 || breakWall == 3) {

                        mazeBoard[i][j].breakWall(2);
                        if (j < cols - 1)mazeBoard[i][j + 1].breakWall(3);

                        mazeBoard[i][j].breakWall(1);
                        if (i < rows - 1)mazeBoard[i + 1][j].breakWall(0);
                    }
                    else if (breakWall == 1 || breakWall == 4) {
                        mazeBoard[i][j].breakWall(2);
                        if (j < cols - 1)mazeBoard[i][j + 1].breakWall(3);
                    }
                    else if (breakWall == 2 || breakWall == 5) {
                        mazeBoard[i][j].breakWall(1);
                        if (i < rows - 1)mazeBoard[i + 1][j].breakWall(0);
                    }
                }
                if (mazeBoard[i][j - 1].checkWall(1) == true) {
                    if (breakWall < 3) {
                        mazeBoard[i][j].breakWall(2);
                        if (j < cols - 1)mazeBoard[i][j + 1].breakWall(3);
                    }
                    else {
                        mazeBoard[i][j].breakWall(1);
                        if (i < rows - 1)mazeBoard[i + 1][j].breakWall(0);
                    }
                }
                else if (j < cols - 1) {
                    mazeBoard[i][j].breakWall(2);
                    mazeBoard[i][j + 1].breakWall(3);
                }
            }
            else if (j > 0 && i == rows - 1) { // if we are in bottom row
                if (mazeBoard[i - 1][j].checkWall(1) == true || mazeBoard[i - 1][j].checkWall(2) == true) {
                    if (j < cols - 1) {
                        mazeBoard[i][j].breakWall(2);
                        mazeBoard[i][j + 1].breakWall(3);
                    }
                }
                if (j == cols - 1) { // if we are in the bottom right corner
                    mazeBoard[i][j].breakWall(0);
                    mazeBoard[i-1][j].breakWall(1);
                    mazeBoard[i][j].breakWall(3);
                    mazeBoard[i][j-1].breakWall(2);
                }
            }
            else {
                if (breakWall == 0 || breakWall == 3) {
                    mazeBoard[i][j].breakWall(2); // to break the right wall of the current cell
                    if (j < cols - 1) mazeBoard[i][j + 1].breakWall(3); // to break to left wall of the next cell
                    if (i < rows - 1) {
                        mazeBoard[i][j].breakWall(1); // to break the bottom wall the current cell
                        mazeBoard[i + 1][j].breakWall(0);;// to break the up wall of the down cell
                    }
                }

                else if (breakWall == 1 || breakWall == 4) {
                    mazeBoard[i][j].breakWall(2); // to break the right wall of the current cell
                    if (j < cols - 1) mazeBoard[i][j + 1].breakWall(3); // to break to left wall of the next cell
                }

                else if (breakWall == 2 || breakWall == 5) { // if to break one wall
                    if (i < rows - 1) {
                        mazeBoard[i][j].breakWall(1); // to break the bottom wall the current cell
                        mazeBoard[i + 1][j].breakWall(0);// to break the up wall of the down cell
                    }
                }
            }
        }
    }
    maze->setMazeBoard(mazeBoard);
    return *maze;

}
