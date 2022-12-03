// CHEM 274B Final Project: Cellular Automata Library
// Shiqi Zhang, Jerry Pan, Wang Xu
// December 2022

// Directory Path: Src/ca_operators.cpp
// This file contains the c++ implementation of the
// cellular automata operations for the cellular automata library.

#include "cellular_automata.h"
#include <iostream>

// Specification for cellular_automata's attributes
// // The maximum size of the grid is 500x500
// #define MAX_SIZE 500
// // Neighborhood types
// #define VON_NEUMAN 1 // up, down, left, right
// #define MOOR 2       // up, down, left, right, up-left, up-right, down-left, down-right
// // Boundary types
// #define NO_BOUNDARY 11 // no boundary - infinite grid
// #define PERIODIC 12    // periodic boundary - the grid is a 1D ring or 2D torus
// #define WALLED 13      // walled boundary - the grid is a 1D or 2D rectangle with walls
// #define CUTOFF 14      // cutoff boundary - the grid is a 1D or 2D rectangle with cutoff edges
// // Rule types
// #define MAJORITY 21   // majority rule - the cell takes the majority state of its neighbors
// #define PARITY_XOR 22 // parity rule - the cell takes the parity of its neighbors

// evolve(): evolve the cellular automata with the defined rule for a given number of steps and modify the current state of the cellular automata in place
// Input: cellular_automata, number of steps, rule type, neighborhood type, boundary type
// Output: none. Modify the current state of the cellular automata in place.
void evolve(cellular_automata &ca, int steps)
{
    using namespace std;

    int rule_type = ca.get_rule_type();
    int neighborhood_type = ca.get_neighborhood_type();
    int boundary_type = ca.get_boundary_type();
    int radius = ca.get_radius();

    // Check if the rule type is valid
    if (rule_type != MAJORITY && rule_type != PARITY_XOR)
    {
        cout << "Invalid rule type!" << endl;
        return;
    }
    // Check if the neighborhood type is valid
    if (neighborhood_type != VON_NEUMAN && neighborhood_type != MOOR)
    {
        cout << "Invalid neighborhood type!" << endl;
        return;
    }
    // Check if the boundary type is valid
    if (boundary_type != NO_BOUNDARY && boundary_type != PERIODIC && boundary_type != WALLED && boundary_type != CUTOFF)
    {
        cout << "Invalid boundary type!" << endl;
        return;
    }
    // Check if the number of steps is valid
    if (steps <= 0)
    {
        cout << "Invalid number of steps!" << endl;
        return;
    }

    // Get the number of dimensions
    int ndims = ca.get_ndims();
    if (ndims != 2)
    {
        cout << "Invalid number of dimensions!" << endl;
        return;
    }
    // Get the dimensions
    int width = ca.get_width();
    int height = ca.get_height();

    // Now we only support WALLED boundary type
    if (boundary_type == WALLED)
    {
        // Evolve the cellular automata for a given number of steps
        for (int step = 0; step < steps; step++)
        {
            // Evolve the cellular automata for one step
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (ca.get_cell(i, j).get_state() == STATE2)
                    {
                        ca.get_cell(i, j).set_state(STATE3);
                    }
                    else if (ca.get_cell(i, j).get_state() == STATE1)
                    {
                        // Get the number of neighbors
                        int num_neighbors = 0;
                        // Get the number of neighbors in state 2
                        int num_neighbors_state2 = 0;
                        for (int neighbor_i = i - radius; neighbor_i <= i + radius; neighbor_i++)
                        {
                            for (int neighbor_j = j - radius; neighbor_j <= j + radius; neighbor_j++)
                            {
                                // Check if the neighbor is inside the grid
                                if (neighbor_i >= 0 && neighbor_i < height && neighbor_j >= 0 && neighbor_j < width)
                                {
                                    // Check if the neighbor not is the current cell and inside the radius
                                    if ((neighbor_i != i || neighbor_j != j) && neighborhood_check(neighborhood_type, i, j, neighbor_i, neighbor_j, height, width, radius))
                                    {
                                        num_neighbors++;
                                        if (ca.get_cell(neighbor_i, neighbor_j).get_state() == STATE2)
                                        {
                                            num_neighbors_state2++;
                                        }
                                    }
                                }
                            }
                        }
                        if (rule_type == MAJORITY)
                        {
                            if (num_neighbors_state2 > num_neighbors / 2)
                            {
                                ca.get_cell(i, j).set_state(STATE2);
                            }
                        }
                        else if (rule_type == PARITY_XOR)
                        {
                            if (num_neighbors_state2 > 0)
                            {
                                ca.get_cell(i, j).set_state(STATE2);
                            }
                        }
                    }
                }
            }
        }

        return;
    }
}

// neighborhood_check whether the neighbor is inside the grid according to the neighborhood type
// Input: the current cell, the neighbor, the neighborhood type
// Output: true if the neighbor is inside the grid, false otherwise
bool neighborhood_check(int neighborhood_type, int i, int j, int neighbor_i, int neighbor_j, int height, int width, int radius)
{
    // Check if the neighbor is inside the grid
    if (neighborhood_type == VON_NEUMAN)
    {
        // Check if the neighbor is inside the grid
        if (neighbor_i >= 0 && neighbor_i < height && neighbor_j >= 0 && neighbor_j < width)
        {
            // Check if the neighbor is inside the radius
            if ((abs(neighbor_i - i) <= radius && neighbor_j == j) && (abs(neighbor_j - j) <= radius && neighbor_i == i))
            {
                return true;
            }
        }
    }
    else if (neighborhood_type == MOOR)
    {
        // Check if the neighbor is inside the grid
        if (neighbor_i >= 0 && neighbor_i < height && neighbor_j >= 0 && neighbor_j < width)
        {
            // Check if the neighbor is inside the radius
            if (abs(neighbor_i - i) <= radius && abs(neighbor_j - j) <= radius)
            {
                return true;
            }
        }
    }
    return false;
}