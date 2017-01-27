// Project #1
// Zachary Neveu, neveu.z@husky.neu.edu
// Jake Dec, dec.j@husky.neu.edu

// This file contains the testing conditions for part A of the Mastermind
// project. It created a length 5 vector with the range [0,10) and runs the
// three provided test cases against the code.

#include<iostream> //standard inputs and outputs
#include<vector> //necessary to store code as vector
#include "code.h" //user made file with code class
#include "response.h" //user made file with code class
#include "mastermind.h" //user made file with code class

#define ROUNDS 10 //Number of rounds here so it is accessible

using namespace std; //standard name space

void getCodeValues(int &n, int &m);

int main()
{
	//Get inputs for Random Generator
	int length = 5;
	int	MaxValue = 10; //n=code length, m=max digit value

					   //initialize the code to be guessed within the specified parameters
	code secretCode(length, MaxValue);

	//Vector to store guess
	vector<int> guessVector;

	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			int guessArray1[5] = { 5, 0, 3, 2, 6 };
			vector<int> guess1Vector(guessArray1, guessArray1 + 5);
			guessVector = guess1Vector;
			cout << "Guess 1: {5, 0, 3, 2, 6}" << endl;
		}
		else if (i == 1)
		{
			int guessArray2[5] = { 2, 1, 2, 2, 2 };
			vector<int> guess2Vector(guessArray2, guessArray2 + 5);
			guessVector = guess2Vector;
			cout << "Guess 2: {2, 1, 2, 2, 2}" << endl;
		}
		else
		{
			int guessArray3[5] = { 1, 3, 3, 4, 5 };
			vector<int> guess3Vector(guessArray3, guessArray3 + 5);
			guessVector = guess3Vector;
			cout << "Guess 3: {1, 3, 3, 4, 5}" << endl;
		}


		//initialize code object for guess vector
		code guess(guessVector, MaxValue);

		//Store  number correct as int so only one call needed
		int correct = secretCode.checkCorrect(guess);

		//If answer not completely correct
		if (correct < secretCode.getLength())
		{
			//print number of correct digits
			cout << "Correct: " << correct << endl;
			//Print number of incorrect digits
			cout << "Incorrect: " << secretCode.checkIncorrect(guess) << endl;
		}

		else //correct==n && tries<10
		{
			cout << "You Win!!" << endl;
			break;//End game
		}
	}//End for loop for three guesses



	 //exit program
	return 0;
}//End Main Function

void getCodeValues(int &n, int &m) {
	printf("What is the desired length of the code: ");
	cin >> n;
	printf("What is the desired range for the code [0,m): ");
	cin >> m;
}


