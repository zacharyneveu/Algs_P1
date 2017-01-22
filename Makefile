COMPILER=g++
CLASS=code
MAIN=mastermind_main
DEPS=code.h, code.cpp

debug: code.cpp
	$(COMPILER) -g -Wall $(MAIN).cpp -o $(MAIN)

production: code.cpp
	$(COMPILER) $(MAIN).cpp -o $(MAIN)
