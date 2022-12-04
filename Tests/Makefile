# CHEM 274B Final Project: Cellular Automata Library
# Shiqi Zhang, Jerry Pan, Wang Xu
# December 2022

# Directory Path: Src/Makefile
# This makefile creates objects from Data Structures and Classes.
# after creation the objects are relocated to the ../Libdir directory

# GNU C++ Compiler
CPP         = g++      # C++ Compuler

# compiler flags -g debug, -O2 optimized version -c create a library object
CPPFLAGS    = -g    

# The directory where the include files needed to create the library objects are
INC_DIR = ../Include

# The directory where all object files are going to moved afer creation
LIB_DIR     = ../Libdir

# The directory where all executable files are going to moved afer creation
BIN_DIR = ../Bindir

# The next line contains the list of datatype object files created 
# by this Makefile. These are the targets this makefile builds
EXECUTABLES = ca_evolve_sanity_test

ca_evolve_sanity_test: $(INC_DIR)/ca_operators.h $(INC_DIR)/cellular_automata.h 
	$(CPP) $(CPPFLAGS) -o ca_evolve_sanity_test ca_evolve_sanity_test.cpp -I$(INC_DIR) $(LIB_DIR)/ca_operators.o $(LIB_DIR)/cellular_automata.o 
	mv ca_evolve_sanity_test $(BIN_DIR)

all:	
	make $(DATA_OBJS)

cleanall:
	cd $(BIN_DIR); rm $(EXECUTABLES)

