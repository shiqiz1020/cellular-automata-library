// CHEM 274B Final Project: Cellular Automata Library
// Shiqi Zhang, Jerry Pan, Wang Xu
// December 2022

// Directory Path: Test/ca_operators.cpp
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
    cellular_automata *CA = new cellular_automata();
    CA->setup_dimension(2, 10, 10);
    CA->setup_neighborhood(MOOR);
    CA->setup_boundary(WALLED, 1);
    CA->setup_nstates(4);
    CA->setup_rules_prob(MAJORITY, 0.5);

    // Evolve the CA for 100 steps.
    evolve(*CA, 100, "../Utils/Data/log.txt");

    return 0;
}