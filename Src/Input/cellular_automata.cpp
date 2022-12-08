// CHEM 274B Final Project: Cellular Automata Library
// Shiqi Zhang, Jerry Pan, Wang Xu
// December 2022

// Directory Path: Src/Input/cellular_automata.cpp
// This file contains the c++ implementation of the
// cellular automata data structure.

#include "cellular_automata.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

// function: Cell::Cell()
// description: The constructor of the cell class.
// input: The x coordinate, y coordinate, and state of the cell.
// output: None.
Cell::Cell()
{
    this->x = -1;
    this->y = -1;
    this->state = -1;
}

// function: Cell::Cell()
// description: The constructor of the cell class.
// input: The x coordinate, y coordinate, and state of the cell.
// output: None.
Cell::Cell(int x, int y, int state)
{
    this->x = x;
    this->y = y;
    this->state = state;
}

// function: Cell::get_x()
// description: The function to get the x coordinate of the cell.
// input: None.
// output: The x coordinate of the cell.
int Cell::get_x()
{
    return this->x;
}

// function: Cell::set_x()
// description: The function to get the x coordinate of the cell.
// input: None.
// output: 1 on success
int Cell::set_x(int x)
{
    this->x = x;
    return 1;
}

// function: Cell::get_y()
// description: The function to get the y coordinate of the cell.
// input: None.
// output: The y coordinate of the cell.
int Cell::get_y()
{
    return this->y;
}

// function: Cell::set_y()
// description: The function to get the y coordinate of the cell.
// input: None.
// output: 1 on success
int Cell::set_y(int y)
{
    this->y = y;
    return 1;
}

// function: Cell::get_state()
// description: The function to get the state of the cell.
// input: None.
// output: The state of the cell.
int Cell::get_state()
{
    return this->state;
}

// function: Cell::set_state(int state)
// description: The function to set the state of the cell.
// input: The state of the cell.
// output: 1 on success
int Cell::set_state(int state)
{
    this->state = state;
    return 1;
}

// function: cellular_automata::cellular_automata()
// description: The constructor of the cellular automata class.
// input: None.
// output: None.
cellular_automata::cellular_automata()
{
    // this->CA = NULL;
    this->CA_data = NULL;
    this->width = -1;
    this->height = -1;
    this->neighborhood_type = -1;
    this->boundary_type = -1;
    this->radius = -1;
    this->num_states = -1;
    this->rule_type = -1;
    this->prob = -1;
    this->init_state = -1;
    this->allow_config_update = true;
}

// function: cellular_automata::~cellular_automata()
// description: The destructor of the cellular automata class.
// input: None.
// output: None.
cellular_automata::~cellular_automata()
{
    if (this->CA_data != NULL)
    {
        for (int i = 0; i < this->height; i++)
        {
            delete[] this->CA_data[i];
        }
        delete[] this->CA_data;
    }
}

// function: cellular_automata::setup_type()
// description: The function to set up the type of the CA.
// input: The type of the CA.
// output: 1 on success.
int cellular_automata::setup_type(CA_type type)
{
    this->CA = type;
    return 1;
}

// function: cellular_automata::setup_dimension()
// description: The function to set up the dimensions of the CA.
// input: The number of dimensions, the width, and the height of the CA.
// output: 1 on success, -1 on not 2D, -2 on allocation error, -4 on invalid dimension.
int cellular_automata::setup_dimension(int ndims, int dim1, int dim2)
{
    if (ndims != 2)
    {
        return -1;
    }
    if (dim1 <= 0 || dim2 <= 0)
    {
        return -4;
    }
    this->width = dim1;
    this->height = dim2;
    this->ndims = ndims;
    this->CA_data = new (nothrow) Cell *[this->height];
    if (this->CA_data != NULL)
    {
        for (int i = 0; i < this->height; i++)
        {
            this->CA_data[i] = new (nothrow) Cell[this->width];
            if (this->CA_data[i] != NULL)
            {
                for (int j = 0; j < this->width; j++)
                {
                    // this->CA_data[i][j] = Cell(j, i, 0);
                    this->CA_data[i][j].set_state(STATE1);
                    this->CA_data[i][j].set_x(j);
                    this->CA_data[i][j].set_y(i);
                }
            }
            else
            {
                for (int k = 0; k < i; k++)
                {
                    delete[] this->CA_data[k];
                }
                return -2;
            }
        }
    }
    else
    {
        return -2;
    }

    return 1;
}

// function: cellular_automata::setup_neighborhood()
// description: The function to set up the neighborhood of the CA.
// input: The type of the neighborhood.
// output: 1 on success, -2 on making update after setup stage, -3 on invalid neighborhood type.
int cellular_automata::setup_neighborhood(int neighborhood_type)
{
    if (neighborhood_type != 1 && neighborhood_type != 2)
    {
        return -3;
    }
    if (this->allow_config_update == false)
    {
        return -2;
    }
    this->neighborhood_type = neighborhood_type;
    return 1;
}

// function: cellular_automata::setup_boundary()
// description: The function to set up the boundary of the CA.
// input: The type of the boundary and the radius of the boundary.
// output: 1 on success, -2 on making update after setup stage, -3 on invalid boundary type, -4 on invalid radius.
int cellular_automata::setup_boundary(int boundary_type, int radius)
{
    if (boundary_type < 11 || boundary_type > 14)
    {
        return -3;
    }
    if (radius <= 0)
    {
        return -4;
    }
    if (this->allow_config_update == false)
    {
        return -2;
    }
    this->boundary_type = boundary_type;
    this->radius = radius;
    return 1;
}

// function: cellular_automata::setup_nstates()
// description: The function to set up the number of states of the CA.
// input: The number of states of the CA.
// output: 1 on success, -2 on making update after setup stage, -4 on invalid nstates.
int cellular_automata::setup_nstates(int nstates)
{
    if (nstates <= 0)
    {
        return -4;
    }
    if (this->allow_config_update == false)
    {
        return -2;
    }
    this->num_states = nstates;
    return 1;
}

// function: cellular_automata::update_config()
// description: The function to update the configuration of the CA.
// input: the specific state of the cell, the probability of the state.
// output: 1 on success, -3 on invalid state, -4 on invalid prob.
int cellular_automata::update_config(int x_state, double prob)
{
    if (x_state < 0 || x_state % 10 > this->num_states)
    {
        return -3;
    }

    if (prob < 0 || prob > 1)
    {
        return -4;
    }
    this->init_state = x_state;
    this->prob = prob;
    srand(time(NULL));

    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            if (rand() % 100 < this->prob * 100)
            {
                this->CA_data[i][j].set_state(this->init_state);
            }
            else
            {
                this->CA_data[i][j].set_state(STATE1);
            }
        }
    }
    this->CA_data[int(this->height / 2)][int(this->width / 2)].set_state(STATE3);

    return 1;
}

// function: cellular_automata::disable_config_update()
// description: The function to disable the configuration update of the CA.
// input: None.
// output: 1 on allow update, 0 on not allow update.
int cellular_automata::disable_config_update()
{
    this->allow_config_update = false;
    return this->allow_config_update == true;
}

// function: cellular_automata::enable_config_update()
// description: The function to enable the configuration update of the CA.
// input: None.
// output: 1 on allow update, 0 on not allow update.
int cellular_automata::enable_config_update()
{
    this->allow_config_update = true;
    return this->allow_config_update == true;
}

// function: cellular_automata::setup_rules_prob()
// description: The function to set up the rules of the CA.
// input: The type of the rule and the probability of the state.
// Note: prob can be -1 if the field is not intended to be used.
// output: 1 on success, -2 on making update after setup stage, -3 on invalid rule type, -4 on invalid prob.
int cellular_automata::setup_rules_prob(int rule_type, double prob)
{
    if (this->allow_config_update == false)
    {
        return -2;
    }
    if (rule_type != 21 && rule_type != 22)
    {
        return -3;
    }
    if (prob < 0 || prob > 1)
    {
        return -4;
    }
    this->rule_type = rule_type;
    if (prob != -1)
    {
        this->prob = prob;
    }
    return 1;
}

// function: cellular_automata::get_ndims()
// description: The function to get the number of dimensions of the CA.
// input: None.
// output: The number of dimensions of the CA.
int cellular_automata::get_ndims()
{
    return this->ndims;
}

// function: cellular_automata::get_width()
// description: The function to get the width of the CA.
// input: None.
// output: The width of the CA.
int cellular_automata::get_width()
{
    return this->width;
}

// function: cellular_automata::get_height()
// description: The function to get the height of the CA.
// input: None.
// output: The height of the CA.
int cellular_automata::get_height()
{
    return this->height;
}

// function: cellular_automata::get_neighborhood_type()
// description: The function to get the neighborhood type of the CA.
// input: None.
// output: The neighborhood type of the CA.
int cellular_automata::get_neighborhood_type()
{
    return this->neighborhood_type;
}

// function: cellular_automata::get_boundary_type()
// description: The function to get the boundary type of the CA.
// input: None.
// output: The boundary type of the CA.
int cellular_automata::get_boundary_type()
{
    return this->boundary_type;
}

// function: cellular_automata::get_radius()
// description: The function to get the radius of the CA.
// input: None.
// output: The radius of the CA.
int cellular_automata::get_radius()
{
    return this->radius;
}

// function: cellular_automata::get_num_states()
// description: The function to get the number of states of the CA.
// input: None.
// output: The number of states of the CA.
int cellular_automata::get_num_states()
{
    return this->num_states;
}

// function: cellular_automata::get_rule_type()
// description: The function to get the rule type of the CA.
// input: None.
// output: The rule type of the CA.
int cellular_automata::get_rule_type()
{
    return this->rule_type;
}

// function: cellular_automata::get_prob()
// description: The function to get the probability of the CA.
// input: None.
// output: The probability of the CA.
double cellular_automata::get_prob()
{
    return this->prob;
}

// function: cellular_automata::get_cell()
// description: The function to get the cell of the CA.
// input: The x and y coordinate of the cell.
// output: The cell of the CA.
Cell *cellular_automata::get_cell(int x, int y)
{
    return &(this->CA_data[y][x]);
}

// function: cellular_automata::get_cell_state()
// description: The function to get the state of the cell of the CA.
// input: The Cell of the CA.
// output: The state of the cell of the CA.
int cellular_automata::get_cell_state(Cell *cell)
{
    return cell->get_state();
}

// function: cellular_automata::set_cell_state()
// description: The function to set the state of the cell of the CA.
// input: The Cell of the CA and the state of the cell.
// output: 1 on success.
int cellular_automata::set_cell_state(Cell *cell, int state)
{
    return cell->set_state(state);
}
