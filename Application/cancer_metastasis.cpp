// CHEM 274B Final Project: Cellular Automata Library
// Shiqi Zhang, Jerry Pan, Wang Xu
// December 2022

// Directory Path: Application/cancer_matastasis.cpp
// This file contains the c++ implementation of the
// cancer matastasis simulation application for the
// cellular automata library.

#include "library.h"
#include <iostream>
#include <string>

using namespace std;

// int main(int argc, char** argv) {
int main()
{
    int err;

    /* ===== Scenario 1 ===== */
    /* Initialization */
    // The scenario for the cellular automata is cancer metastasis.
    CA_type type = {"cancer_metastasis"};

    // Create a CA object.
    cellular_automata *CA = CA_create(type);

    // Set up and initialize the CA to be a 500x500 grid
    //     with MOORE neighborhood,
    //     walled boundary, and majority rule;.

    err = CA_setup_dimension(CA, 2, 100, 100);
    if (err != 1)
    {
        cout << "Error at CA_setup_dimension: " << err << endl;
        return -1;
    }
    err = CA_setup_neighborhood(CA, MOORE);
    if (err != 1)
    {
        cout << "Error at CA_setup_neighborhood: " << err << endl;
        return -1;
    }
    err = CA_setup_boundary(CA, WALLED, 1);
    if (err != 1)
    {
        cout << "Error at CA_setup_boundary: " << err << endl;
        return -1;
    }
    err = CA_setup_rules(CA, PARITY_XOR);
    if (err != 1)
    {
        cout << "Error at CA_setup_rules: " << err << endl;
        return -1;
    }

    /* Definition of States */
    // Non-cancer cell is represented by 31, dark green
    // Benevolent cancer cell is represented by 32, light green
    // Malignant cancer cell is represented by 33, yellow
    // Apoptotic cell is represented by 34, red
    err = CA_setup_nstates(CA, 4);
    if (err != 1)
    {
        cout << "Error at CA_setup_nstates: " << err << endl;
        return -1;
    }

    // Set up the initial state of the CA to be benevolent cancer cell
    // with probability of transition into benMalignantevolent cancer cell
    // at 0.2.

    err = CA_init_config(CA, STATE2, 0.8);
    if (err != 1)
    {
        cout << "Error at CA_init_config: " << err << endl;
        return -1;
    }

    /* Simulation of propagation */
    // Evolve the CA for 100 steps and store the result in
    // ./Compute_Results/scenario_1.txt.
    err = CA_evolve(CA, 100, "./Application/Compute_Results/scenario_1.txt");
    if (err != 1)
    {
        cout << "Error at CA_evolve: " << err << endl;
        return -1;
    }

    // Print out the percentage of each state in the CA.
    cout << "At step 50, the percentage of non-cancer cells is " << CA_get_state_percentage(CA, 50, 31) << endl;
    cout << "At step 50, the percentage of benevolent cancer cells is " << CA_get_state_percentage(CA, 50, 32) << endl;
    cout << "At step 50, the percentage of malignant cancer cells is " << CA_get_state_percentage(CA, 50, 33) << endl;
    cout << "At step 50, the percentage of apoptotic cells is " << CA_get_state_percentage(CA, 50, 34) << endl;
    cout << endl;
    cout << "At step 100, the percentage of non-cancer cells is " << CA_get_state_percentage(CA, 100, 31) << endl;
    cout << "At step 100, the percentage of benevolent cancer cells is " << CA_get_state_percentage(CA, 100, 32) << endl;
    cout << "At step 100, the percentage of malignant cancer cells is " << CA_get_state_percentage(CA, 100, 33) << endl;
    cout << "At step 100, the percentage of apoptotic cells is " << CA_get_state_percentage(CA, 100, 34) << endl;
    cout << endl;

    return 0;
}
