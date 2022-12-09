// CHEM 274B Final Project: Cellular Automata Library
// Shiqi Zhang, Jerry Pan, Wang Xu
// December 2022

// Directory Path: Src/Input/input.cpp
// This file contains the c++ implementation of the
// input setup phase for the cellular automata library.

#include "library.h"
// #include "cellular_automata.h"

using namespace std;

// function: CA_create()
// description: The function to create a CA object.
// input: The type of the CA.
// output: The cellular_automata object.
cellular_automata *CA_create(CA_type type)
{
    cellular_automata *CA = new cellular_automata();
    CA->setup_type(type);
    return CA;
}

// function: CA_setup_dimension()
// description: The function to set up the dimensions of the grid.
// input: The cellular automata object, the number of dimensions, the first dimension, and the second dimension.
// output: refer to "Include/error_code.h" for error codes.
int CA_setup_dimension(cellular_automata *CA, int ndims, int dim1, int dim2)
{
    return CA->setup_dimension(ndims, dim1, dim2);
}

// function: CA_setup_neighborhood()
// description: The function to set up neighborhood rule.
// input: The cellular automata object, the neighborhood type.
// output: refer to "Include/error_code.h" for error codes.
int CA_setup_neighborhood(cellular_automata *CA, int neighborhood_type)
{
    return CA->setup_neighborhood(neighborhood_type);
}

// function: CA_setup_boundary()
// description: The function to set up boundary rule and radius.
// input: The cellular automata object, the boundary type, and the radius.
// output: refer to "Include/error_code.h" for error codes.
int CA_setup_boundary(cellular_automata *CA, int boundary_type, int radius)
{
    return CA->setup_boundary(boundary_type, radius);
}

// function: CA_setup_nstates()
// description: The function to set up the number of states.
// input: The cellular automata object, the number of states.
// output: refer to "Include/error_code.h" for error codes.
int CA_setup_nstates(cellular_automata *CA, int nstates)
{
    if (nstates < 4)
    {
        return -4;
    }
    return CA->setup_nstates(nstates);
}

// function: CA_init_config()
// description: The function to set up the initial configuration for the state of the automation
// and the probability of a cell entering state x from an empty cell.
// input: The cellular automata object, the state of the cell, and the probability.
// output: refer to "Include/error_code.h" for error codes.
int CA_init_config(cellular_automata *CA, int x_state, double prob)
{
    return CA->update_config(x_state, prob);
}

// function: CA_init_rewrite_config()
// description: The function to rewrite the initial configuration.
// input: The cellular automata object, the state of the cell, and the probability.
// output: refer to "Include/error_code.h" for error codes.
int CA_init_rewrite_config(cellular_automata *CA, int x_state, double prob)
{
    return CA->update_config(x_state, prob);
}

// function: CA_setup_rules()
// description: The function to set up the basic CA rules for computation.
// input: The cellular automata object, the rule type.
// output: refer to "Include/error_code.h" for error codes.
int CA_setup_rules(cellular_automata *CA, int rule_type)
{
    return CA->setup_rules_prob(rule_type, -1);
}

// function: CA_setup_rules_prob()
// description: The function to set up the basic CA rules for computation with probability.
// input: The cellular automata object, the rule type, and the probability.
// output: refer to "Include/error_code.h" for error codes.
int CA_setup_rules_prob(cellular_automata *CA, int rule_type, double prob)
{
    return CA->setup_rules_prob(rule_type, prob);
}
