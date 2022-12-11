# Cellular-Automata-Library
# University of California, Berkeley
# Chem 274B: Introduction to Software Engineering
# Creator: Shiqi Zhang, Jerry Pan, Wang Xu
# December 2022
# Directory Path: cellular-automata-library/Application

 This subdirectory contains the c++ implementation of the
 cancer matastasis simulation application for the
 cellular automata library. The Makefile in this directory 
 can execute command line statements to run the cancer_metastasis.cpp 
 and cleanup of the program.

 Files and Subdirectories:
  - README: (this file) has a general description of the test programs.

  - Makefile: # This makefile creates objects from basic tests for the 
    cellular automata library. After creation the objects are relocated 
    to the ../Bindir directory

  - cancer_metastasis.cpp: This file contains the c++ implementation for the
    cancer cell metastatis model of the cellular automata operations for the 
    cellular automata library

  - Compute_Results: this subdirectory contains the calculated data from
    cancer_metastasis.cpp

  - Plot_Results: this subdirectory contains all the saved figures from the
    application executable