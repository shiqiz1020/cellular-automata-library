// CHEM 274B Final Project: Cellular Automata Library
// Shiqi Zhang, Jerry Pan, Wang Xu
// December 2022

// Directory Path: Include/ca_operators.h
// This file contains the c++ implementation of the
// cellular automata operations for the cellular automata library.
#include <string>

using namespace std;
#include "cellular_automata.h"

// evolve(): evolve the cellular automata with the defined rule for a given number of steps and modify the current state of the cellular automata in place
// Input: cellular_automata, number of steps, output log file name
// Output: none. Modify the current state of the cellular automata in place.
void evolve(cellular_automata ca, int steps, string log_file_name);

// neighborhood_check whether the neighbor is inside the grid according to the neighborhood type
// Input: the current cell, the neighbor, the neighborhood type
// Output: true if the neighbor is inside the grid, false otherwise
bool neighborhood_check(int neighborhood_type, int i, int j, int neighbor_i, int neighbor_j, int height, int width, int radius);

// The functino to return the percentage of x_state in the result CA
// double CA_get_percentage(cellular_automata CA, int x_state);