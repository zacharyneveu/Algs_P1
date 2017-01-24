COMPILER=g++
CLASS=code
MAIN=mastermind_main.cpp
DEPS=code.h, code.cpp

partA: code.cpp
	$(COMPILER) PartA.cpp -o PartA

debug: code.cpp
	$(COMPILER) -g -Wall $(MAIN).cpp -o $(MAIN)

production: code.cpp
	$(COMPILER) $(MAIN).cpp -o $(MAIN)
