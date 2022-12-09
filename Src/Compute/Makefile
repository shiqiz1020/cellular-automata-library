# CHEM 274B Final Project: Cellular Automata Library
# Shiqi Zhang, Jerry Pan, Wang Xu
# December 2022

# Directory Path: Src/Compute/Makefile
# This makefile creates objects from the cellular automata compute operations.
# after creation the objects are relocated to the ../../Libdir directory

# GNU C++ Compiler
CPP         = g++      # C++ Compuler

# compiler flags -g debug, -O2 optimized version -c create a library object
CPPFLAGS    = -g -c    

# The directory where the include files needed to create the library objects are
INC_DIR = ../../Include

# The directory where all object files are going to moved afer creation
LIB_DIR     = ../../Libdir

# The next line contains the list of datatype object files created 
# by this Makefile. These are the targets this makefile builds
DATA_OBJS = ca_operators.o 

ca_operators.o:  $(INC_DIR)/error_code.h
	$(CPP) $(CPPFLAGS) ca_operators.cpp -I$(INC_DIR) $(LIB_DIR)/cellular_automata.o 
	mv ca_operators.o $(LIB_DIR)

all:	
	make $(DATA_OBJS)

cleanall:
	cd $(LIB_DIR); rm $(DATA_OBJS)

