COMPILER=g++
MAIN=../MasterMind/main
FLAGS=-g -Wall
debug: ../MasterMind/code.h ../MasterMind/code.cpp ../MasterMind/response.h ../MasterMind/response.cpp ../MasterMind/mastermind.h ../MasterMind/mastermind.cpp
	$(COMPILER) $(FLAGS) $(MAIN).cpp -o $(MAIN)

production: code.h code.cpp response.h response.cpp mastermind.h mastermind.cpp
	$(COMPILER) $(MAIN).cpp -o $(MAIN)

