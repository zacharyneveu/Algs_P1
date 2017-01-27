#include "mastermind.h"
#include "code.h"
#include "response.h"
#include <iostream>



//humanGuess() reads a guess from the keyboard and returns a code object
//that represents the guess.  Inputs are validated to be the right length
//and to be in range by the code constructor called.
code mastermind::humanGuess() {
	cout<<"Enter a guess leaving a space between each digit: ";

	int digit = 0;//variable to hold value of each digit
	vector<int> guessVector;//Vector to store partial guess code

	//iterate over all digits in code
	for (int i=0; i < n; i++)
	{
		cin>>digit;
		guessVector.push_back(digit);
	}//end of for loop

	//call code constructor to make new code object and validate that inputs
	//are in given range.
	code guess(guessVector,m);
	return guess;
}//end of function

//getResponse() is passed a guess code, and creates a response object using
//the guess code and secret code as arguments for the response
//constructor.  Processing codes into response is done in response
//constructor because there should never be a response created that is not from
//codes.
response mastermind::getResponse(const code &guessCode) {
	int correct = this->secretCode.checkCorrect(guessCode);
	int incorrect = this->secretCode.checkIncorrect(guessCode);
	response guessResponse(correct, incorrect);
	return guessResponse;
}//end of function

//isSolved() is passed a response and returns true if the response is the
//indicates that the code has been guessed
bool mastermind::isSolved(const response &checkResponse) {
	return checkResponse.getCorrect() == n;
}//End of function

//playGame() initializes a random code, prints it to the screen, then
//iteratively gets a guess from the user and prints the response until the
//game is over.
void mastermind::playGame() {

	code secretCode(n, m);
	this->secretCode = secretCode;


	//print secret code (for tests only, disable for playing)
	secretCode.printCode();

	response guessResponse;
	do
	{

		//Let user input a guess
		code guess = humanGuess();

		//determine response to guess
		guessResponse= getResponse(guess);

		//TODO replace with << operator
		cout << "Correct: " << guessResponse.getCorrect() << endl;
		cout << "Incorrect: " << guessResponse.getIncorrect() << endl;

	} while (!isSolved(guessResponse) && --guessesLeft > 0);

		cout << (isSolved(guessResponse) ? "You Won!" : "You Lost!") << endl;
}

