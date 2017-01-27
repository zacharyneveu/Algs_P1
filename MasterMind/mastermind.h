#pragma once
#ifndef MASTERMIND_H
#define MASTERMIND_H

#define ROUNDS 10 //Hard coded but accessible here

//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file contains the definition of the mastermind class for project 1b.
//Implementations for the functions in this class can be found in
//mastermind.cpp.

#include "response.h"
#include "code.h"

class mastermind
{
private:
    code secretCode; //code object to store secret code
	int n, m, guessesLeft; 		 //n=code length, m=Max digit value.
public:
    //Constructor can be passed values for n and m
    mastermind(int n = 5, int m = 10)
    {
		this->n = n;
		this->m = m;
		guessesLeft = ROUNDS;
    }

	//printCode() prints a code by calling the print code function defined in
	//the code class.
	void printCode() {
		//call print function in code class
		this->secretCode.printCode();
	}

    //humanGuess() reads a guess from the keyboard and returns a code object
    //that represents the guess.  Inputs are validated to be the correct
	//length and to be in the correct range by the code constructor called.
	code humanGuess();

	//getResponse() is passed a guess code, and creates a response object
	//using the guess code and secret code as arguments for the
	//response constructor.  Processing codes into a response is done in the
	//response constructor, because it should not be possible to create a
	//response arbitrarily.
    response getResponse(const code &guessCode);

    //isSolved() is passed a response and returns true if the response is the
    //indicates that the code has been guessed
	bool isSolved(const response &checkResponse);

    //playGame() initializes a random code, prints it to the screen, then
    //iteratively gets a guess from the user and prints the response until the
    //game is over.
	void playGame();
};
#endif