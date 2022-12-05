// CHEM 274B Final Project: Cellular Automata Library
// Shiqi Zhang, Jerry Pan, Wang Xu
// December 2022

// Directory Path: Tests/cancer_cell_model.cpp
// This file contains the c++ implementation of the
// cellular automata operations for the cellular automata library.

#include "ca_operators.h"
#include "cellular_automata.h"
#include <iostream>
#include <fstream>

using namespace std;

// Initialize a cellular automata object, and set up the dimension, neighborhood, boundary, and nstates.
int main()
{
    cellular_automata *CancerCell = new cellular_automata();
    CancerCell->setup_dimension(2, 100, 100);
    CancerCell->setup_neighborhood(MOOR);
    CancerCell->setup_boundary(WALLED, 1);
    CancerCell->setup_nstates(4);
    CancerCell->setup_rules_prob(MAJORITY, 0.5);

    // Evolve the CA for 100 steps.
    evolve(*CancerCell, 100, "../Utils/Data/cancercell.txt");

    return 0;
}