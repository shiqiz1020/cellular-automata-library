# UTILDIR = ./util
SRC_INPUT_DIR = ./Src/Input
SRC_COMPUTE_DIR = ./Src/Compute
TESTDIR = ./Tests

all:
#	cd $(UTILDIR); make
	cd $(SRC_INPUT_DIR); make	
	cd $(SRC_COMPUTE_DIR); make

	cd $(TESTDIR); make

clean:
#	cd $(UTILDIR); make clean
	cd $(SRC_INPUT_DIR); make clean
	cd $(SRC_COMPUTE_DIR); make clean
	cd $(TESTDIR); make clean

.PHONY: all clean
