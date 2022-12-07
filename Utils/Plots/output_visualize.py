# CHEM 274B Final Project: Cellular Automata Library
# Shiqi Zhang, Jerry Pan, Wang Xu
# December 2022

# Directory Path: Utils/Plots/output_visualize.py
# This file contains the output visualization of the
# input setup phase for the cellular automata library.

# Only run this file under root directory of the project.

# Simple CA simulator in Python

# *** Cancer Metastasis ***

import matplotlib
import matplotlib.pyplot as plt

# import the python libraries random (RD), SciPy (SP)
import random as RD
import scipy as SP
import pandas as pd

RD.seed()

# Initialize and construct result matrix
def construct_matrix():
    next(input_file)

    result = SP.zeros([height, width])
    for i in range(height):
        result[i] = [int(item) for item in next(input_file).split()]
    return result

# Visualize the matrix
def visualize(step, ndims, width, height, nstates, initProb):
    plt.cla()
    plt.pcolor(result, vmin = 31, vmax = (30+nstates), cmap = cmap_reversed, label = result)
    plt.axis('image')
    plt.title('initProb = ' + str(initProb) + ' ,  ' + 't = ' + str(step))

    # Save the plot to a file
    plot_name = f"Utils/Data/Result/result_t_{step}_ndims_{ndims}_width_{width}_height_{height}_nstates_{nstates}_initProb_{initProb}.png"
    plt.savefig(plot_name, bbox_inches='tight', transparent=False)

    # plt.show()
    plt.figure()
    return;

# First parse the acquired txt file
input_file = open('Utils/Data/log.txt', 'r')

# Parse metadadta
metadata = input_file.readline().split()
ndims = int(metadata[0])
width = int(metadata[1])
height = int(metadata[2])
nstates = int(metadata[3])
initProb = float(metadata[4])
steps = int(metadata[5])

# Set Color map
cmap_reversed = matplotlib.cm.get_cmap('RdYlGn_r')

for step in range(1, steps + 1):
    result = construct_matrix()
    visualize(step, ndims, width, height, nstates, initProb)

# Close input file
input_file.close()