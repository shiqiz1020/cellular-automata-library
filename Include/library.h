// CHEM 274B Final Project: Cellular Automata Library
// Shiqi Zhang, Jerry Pan, Wang Xu
// December 2022

// This file contains the API for the cellular automata library.

#include "cellular_automata.h"

using namespace std;

// This function creates a CA object.
cellular_automata* CA_create(CA_type type);
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