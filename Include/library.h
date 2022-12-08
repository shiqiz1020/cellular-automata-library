// CHEM 274B Final Project: Cellular Automata Library
// Shiqi Zhang, Jerry Pan, Wang Xu
// December 2022

// Directory Path: Include/library.h
// This file contains the API for the cellular automata library.

#include "cellular_automata.h"

using namespace std;

// This function creates a CA object.
cellular_automata *CA_create(CA_type type);
// The function to set up the dimensions of the grid.
int CA_setup_dimension(cellular_automata CA, int ndims, int dim1, int dim2);
// The function to set up neighborhood rule.
int CA_setup_neighborhood(cellular_automata CA, int neighborhood_type);
// The function to set up boundary rule and radius.
int CA_setup_boundary(cellular_automata CA, int boundary_type, int radius);
// The function to set up the number of states.
int CA_setup_nstates(cellular_automata CA, int nstates);
// The function to set up the initial configuration for the state of the automation
// and the probability of a cell entering state x from an empty cell.
int CA_init_config(cellular_automata CA, int x_state, double prob);
// The function to rewrite the initial configuration.
int CA_init_rewrite_config(cellular_automata CA, int x_state, double prob);
// The function to set up the basic CA rules for computation.
int CA_setup_rules(cellular_automata CA, int rule_type);
// The function to set up the basic CA rules for computation with probability.
int CA_setup_rules_prob(cellular_automata CA, int rule_type, double prob);
// The function to evolve the cellular automata with the defined rule for a given number of
// steps and modify the current state of the cellular automata in place
void CA_evolve(cellular_automata CA, int steps, string log_file_name);
// The function to check whether the neighbor is inside the grid according to the neighborhood type
bool CA_neighborhood_check(int neighborhood_type, int i, int j, int neighbor_i, int neighbor_j, int height, int width, int radius);
// The functino to return the percentage of x_state in the result CA
double CA_get_state_counts(cellular_automata *CA, int step, int x_state);