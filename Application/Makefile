# CHEM 274B Final Project: Cellular Automata Library
# Shiqi Zhang, Jerry Pan, Wang Xu
# December 2022

# Directory Path: Application/Makefile
# This makefile creates objects for the cancer metastasis simulation application.

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
EXECUTABLES = cancer_metastasis

cancer_metastasis:  $(INC_DIR)/cellular_automata.h $(INC_DIR)/library.h
	$(CPP) $(CPPFLAGS) -o cancer_metastasis cancer_metastasis.cpp -I$(INC_DIR) $(LIB_DIR)/ca_operators.o $(LIB_DIR)/input.o $(LIB_DIR)/cellular_automata.o 
	mv cancer_metastasis $(BIN_DIR)

all:	
	make $(EXECUTABLES)

cleanall:
	cd $(BIN_DIR); rm $(EXECUTABLES)

