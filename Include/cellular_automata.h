// CHEM 274B Final Project: Cellular Automata Library
// Shiqi Zhang, Jerry Pan, Wang Xu
// December 2022

// Directory Path: Include/cellular_automata.h
// This file contains C++ class definition of the basic
// data structures for the cellular automata library.

#include <array>
#include <string>

using namespace std;

// The maximum size of the grid is 500x500
#define MAX_SIZE 500
// Neighborhood types
#define VON_NEUMAN 1
#define MOOR 2
// Boundary types
#define NO_BOUNDARY 11
#define PERIODIC 12
#define WALLED 13
#define CUTOFF 14
// Rule types
#define MAJORITY 21
#define PARITY_XOR 22

// This class defines possible options for the cellular automata
class CA_type {
    string name;
};

// This class defines the basic data structure for a cell.
class Cell {
    public:
        // The constructor of the cell class.
        Cell(int x, int y, int state);
        // The function to get the x coordinate of the cell.
        int get_x();
        // The function to get the y coordinate of the cell.
        int get_y();
        // The function to get the state of the cell.
        int get_state();
        // The function to set the state of the cell.
        int set_state(int state);
    private:
        // The x coordinate of the cell.
        int x;
        // The y coordinate of the cell.
        int y;
        // The state of the cell.
        int state;
};

// This class defines the basic data structure for the CA setup.
class cellular_automata {
    public:
        /* ==== This section includes the methods for the setup phase. ==== */

        // The constructor of the cellular automata class.
        cellular_automata();
        // The destructor of the cellular automata class.
        ~cellular_automata();
        // The function to set up the CA type.
        int setup_type(CA_type CA);
        // The function to set up the dimensions of the grid.
        int setup_dimension(int ndims, int dim1, int dim2);
        // The function to set up neighborhood rule.
        int setup_neighborhood(int neighborhood_type);
        // The function to set up boundary rule and radius.
        int setup_boundary(int boundary_type, int radius);
        // The function to set up the number of states.
        int setup_nstates(int nstates);
        // The function to set up or update the initial configuration for the state 
        // of the automation and the probability of a cell entering state x from an empty cell.
        int update_config(int x_state, double prob);
        // The function to disable further updates to the initial configuration.
        int disable_config_update();
        // The function to enable further updates to the initial configuration.
        int enable_config_update();
        // The function to set up the basic CA rules for computation with probability.
        int setup_rules_prob(int rule_type, double prob);

        /* ==== This section includes the helper methods that might be useful. ==== */

        // The function to get the width of the CA.
        int get_width();
        // The function to get the height of the CA.
        int get_height();
        // The functino to get the neighborhood type of the CA.
        int get_neighborhood_type();
        // The function to get the boundary type of the CA.
        int get_boundary_type();
        // The function to get the radius of the CA.
        int get_radius();
        // The function to get the number of states of the CA.
        int get_num_states();
        // The function to get the rule type of the CA.
        int get_rule_type();
        // The function to get the probability of the CA.
        double get_prob();
        // The function to get the cell at the given coordinate.
        Cell get_cell(int x, int y);
        // The function to get the state of the cell at the given coordinate.
        int get_cell_state(Cell* cell);
        // The function to set the state of the cell at the given coordinate.
        int set_cell_state(Cell* cell, int state);

        // // The function to get the number of neighbors of the CA.
        // int get_num_neighbors();
        // // The function to get the neighbor list of the CA.
        // int* get_neighbor_list();

    private:
        // The cellular automata type.
        CA_type CA;
        // The CA data matrix.
        Cell** CA_data;
        // The width of the CA.
        int width;
        // The height of the CA.
        int height;
        // The neighborhood type of the CA.
        int neighborhood_type;
        // The boundary type of the CA.
        int boundary_type;
        // The radius of the CA.
        int radius;
        // The number of states of the CA.
        int num_states;
        // The initial state of CA
        int init_state;
        // The probability of a cell entering state x from an empty cell.
        double prob;
        // The rule type of the computation.
        int rule_type;
        // The flag to indicate whether the initial configuration can be updated.
        bool allow_config_update;


        // // The number of neighbors of the CA.
        // int num_neighbors;
        // // The neighbor list of the CA.
        // int* neighbor_list;
};
