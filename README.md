# Cellular-Automata-Library
# University of California, Berkeley
# Chem 274B: Introduction to Software Engineering
# Creator: Shiqi Zhang, Jerry Pan, Wang Xu
# December 2022

This is the main directory for the group project, cellular automata library, which
explores programming tools to design and implement cellular automata models to gain 
insights on how these models work.

The directory structure is as follows:
Root directory:
	- README: (this file) General description of the top directory (or repository)
	- Makefile: Global build automation commands. 

Sub-directories:
	- Application/ : this directory contains C++ implementation of 
                application models for cancer cell model and california forest fire
        
        - Bindir/ : this directory contains all the executable program

	- Libdir/ : this directory contains all the object files and
	  libraries (.a or .so or .o)

	- Include/: this directory contains all the APIs in the form
	  of function prototypes, variable definitions and compiler
	  directives (.h).

	- Src/ : Main source library development repository. Include 
                two sub-directories, Input/ and Compute/

	- Tests: Test programs used to check the correctness and  
	         performance of the C++ implementations. Also includes 
                 the application C++ programs.

	- Utils: Contains all the source files that implement 
	         utilities like timing, I/O, and plotting tools. It includes 
                 two sub-directories, Data/ includes all output matrices from 
                 the application programs, Plots/ include the output visualizer 
                 in the format of Python program in Jupyter Notebook. The user 
                 will need to open the Jupyter Notebook and run the corresponding 
                 plotting programs to generate output figures from the cellular 
                 automata modeling.