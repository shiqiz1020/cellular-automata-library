// CHEM 274B Final Project: Cellular Automata Library
// Shiqi Zhang, Jerry Pan, Wang Xu
// December 2022

// Directory Path: Src/Input/ca_operators.cpp
// This file contains the c++ implementation of the
// cellular automata computeoperations for the cellular automata library.

#include "cellular_automata.h"
#include "library.h"
#include "error_code.h"
#include <iostream>
#include <fstream>

// evolve(): evolve the cellular automata with the defined rule for a given number of steps and modify the current state of the cellular automata in place
// Input: cellular_automata, number of steps, output log file name
// Output: Modify the current state of the cellular automata in place.
//         Refer to "Include/error_code.h" for error codes.
int CA_evolve(cellular_automata *CA, int steps, string log_file_name)
{
    using namespace std;

    // Open the log file
    ofstream log_file;
    log_file.open(log_file_name);

    int rule_type = CA->get_rule_type();
    int neighborhood_type = CA->get_neighborhood_type();
    int boundary_type = CA->get_boundary_type();
    int radius = CA->get_radius();

    // Check if the rule type is valid
    if (rule_type != MAJORITY && rule_type != PARITY_XOR)
    {
        return INVALID_RULES;
    }

    // Check if the neighborhood type is valid
    if (neighborhood_type != VON_NEUMAN && neighborhood_type != MOOR)
    {
        return INVALID_NEIGHBORHOOD;
    }

    // Check if the boundary type is valid
    if (boundary_type != NO_BOUNDARY && boundary_type != PERIODIC && boundary_type != WALLED && boundary_type != CUTOFF)
    {
        return INVALID_BOUNDARY;
    }

    // Check if the number of steps is valid
    if (steps <= 0)
    {
        return INVALID_NSTEPS;
    }

    // Get the number of dimensions
    int ndims = CA->get_ndims();
    if (ndims != 2)
    {
        return INVALID_NDIMS;
    }

    // Get the dimensions
    int width = CA->get_width();
    int height = CA->get_height();
    int nstates = CA->get_num_states();

    // Output metadata in the log file in the order:
    // ndims, dim1, dim2, nstates, initProb, steps
    log_file << CA->get_ndims() << " ";
    log_file << width << " ";
    log_file << height << " ";
    log_file << nstates << " ";
    log_file << CA->get_prob() << " ";
    log_file << steps << " ";
    log_file << endl << endl;

    int state_counts[steps][nstates];
    for (int step = 0; step < steps; step++)
    {
        for (int state_idx = 0; state_idx < nstates; state_idx++)
        {
            state_counts[step][state_idx] = 0;
        }
    }

    // Now we only support WALLED boundary type
    if (boundary_type == WALLED)
    {
        // Evolve the cellular automata for a given number of steps
        for (int step = 0; step < steps; step++)
        {
            // Duplicate the current state of the cellular automata as a cellular automata object
            int original_state[width][height];

            // Get the current state of the cellular automata
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    original_state[i][j] = CA->get_cell(i, j)->get_state();
                }
            }

            // Evolve the cellular automata for one step
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    // Get the number of neighbors
                    int num_neighbors = 0;
                    // Get the number of neighbors in state 2
                    int num_neighbors_state2 = 0;

                    if (STATE2 < original_state[i][j] && original_state[i][j] < STATE1 - 1 + nstates)
                    {
                        CA->get_cell(i, j)->set_state(original_state[i][j] + 1);
                    }
                    else if (original_state[i][j] == STATE2)
                    {
                        for (int neighbor_i = i - radius; neighbor_i <= i + radius; neighbor_i++)
                        {
                            for (int neighbor_j = j - radius; neighbor_j <= j + radius; neighbor_j++)
                            {
                                // Check if the neighbor is inside the grid
                                if (neighbor_i >= 0 && neighbor_i < height && neighbor_j >= 0 && neighbor_j < width)
                                {
                                    // Check if the neighbor not is the current cell and inside the radius
                                    if ((neighbor_i != i || neighbor_j != j) && CA_neighborhood_check(neighborhood_type, i, j, neighbor_i, neighbor_j, height, width, radius))
                                    {
                                        num_neighbors++;
                                        if (original_state[neighbor_i][neighbor_j] == STATE3)
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
                                CA->get_cell(i, j)->set_state(STATE3);
                            }
                        }
                        else if (rule_type == PARITY_XOR)
                        {
                            if (num_neighbors_state2 > 0)
                            {
                                CA->get_cell(i, j)->set_state(STATE3);
                            }
                        }
                    }
                    log_file << CA->get_cell(i, j)->get_state() << " ";

                    state_counts[step][CA->get_cell(i, j)->get_state() - STATE1]++;
                }
                log_file << endl;
            }
            log_file << endl;

        }
        // Output the percentage of each state in the log file
        for (int step = 0; step < steps; step++)
        {
            log_file << "Step " << step + 1 << ": ";
            for (int state_idx = 0; state_idx < nstates; state_idx++)
            {
                log_file << state_counts[step][state_idx] << " ";
            }
            log_file << endl;
        }
        log_file.close();
        return SUCCESS;
    }  
    else
    {
        return UNSUPPORTED_BOUNDARY;
    }
}

// neighborhood_check whether the neighbor is inside the grid according to the neighborhood type
// Input: the current cell, the neighbor, the neighborhood type
// Output: true if the neighbor is inside the grid, false otherwise
bool CA_neighborhood_check(int neighborhood_type, int i, int j, int neighbor_i, int neighbor_j, int height, int width, int radius)
{
    // Check if the neighbor is inside the grid
    if (neighborhood_type == VON_NEUMAN)
    {
        // Check if the neighbor is inside the grid
        if (neighbor_i >= 0 && neighbor_i < height && neighbor_j >= 0 && neighbor_j < width)
        {
            // Check if the neighbor is inside the radius
            if ((abs(neighbor_i - i) <= radius && neighbor_j == j) || (abs(neighbor_j - j) <= radius && neighbor_i == i))
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

// The function to return the percentage of x_state in the result CA
double CA_get_state_percentage(cellular_automata *CA, int step, int x_state)
{
    int width = CA->get_width();
    int height = CA->get_height();
    int num_x_state = 0;

    // Get the number of cells in state x_state
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int state = CA->get_cell(i, j)->get_state();
            if (state == x_state)
            {
                num_x_state++;
            }
        }
    }

    return (double) num_x_state / (width * height);
}
