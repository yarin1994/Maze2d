//
// Created by חן גוטמן on 12/08/2020.
//

#include "Maze2dGenerator.h"

string Maze2dGenerator::measureAlgorithmTime(const string &name,int rows, int cols) {
    auto start = high_resolution_clock::now();
    generate(name,rows, cols);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    string message = "the algorithm duration time is: ";
    string str = to_string(duration.count());
    message = message + str;
    return message;

}
