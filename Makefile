SRC_INPUT_DIR = ./Src/Input
SRC_COMPUTE_DIR = ./Src/Compute
TESTDIR = ./Tests
PLOT_RESULT_DIR = ./Utils/Data/Plot_Results
APPLICATION_DIR = ./Application

all:
	cd $(PLOT_RESULT_DIR); rm -f *.png
	cd $(SRC_INPUT_DIR); make all
	cd $(SRC_COMPUTE_DIR); make all
	cd $(TESTDIR); make all
	cd $(APPLICATION_DIR/Plot_Results); rm -f *.png
	cd $(APPLICATION_DIR); make all

app:
	cd $(APPLICATION_DIR/Plot_Results); rm -f *.png
	cd $(APPLICATION_DIR); make all

clean:
	cd $(SRC_INPUT_DIR); make cleanall
	cd $(SRC_COMPUTE_DIR); make cleanall
	cd $(TESTDIR); make cleanall
	cd $(APPLICATION_DIR); make cleanall

