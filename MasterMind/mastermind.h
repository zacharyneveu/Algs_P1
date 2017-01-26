#pragma once

//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file contains the definition of the mastermind class for project 1b.
//Implementations for the functions in this class can be found in
//mastermind.cpp.

class mastermind
{
private:
    code secretCode;
public:
    //Default constructor passes n = 5 and m = 10
    mastermind()
    {
        code createCode(5, 10); //create new code with 5 and 10
        secretCode = createCode; //set secret code to this new code
    }

    //Constructor can be passed values for n and m
    mastermind(int n, int m)
    {
        code createCode(n, m);
        secretCode = createCode;
    }

    //printSC prints Secret Code
    void printSC() const;

    //humanGuess() reads a guess from the keyboard and returns a code object
    //that represents the guess.
    code humanGuess();

    //getResponse() is passed two codes and returns a response.  The first
    //argument is the guess, the second is the secret code.
    response getResponse(const code &guessCode, const code &secretCode);

    //isSolved() is passed a response and returns true if the response is the
    //indicates that the code has been guessed
    bool isSolved(const response &checkResponse);

    //playGame() initializes a random code, prints it to the screen, then
    //iteratively gets a guess from the user and prints the response until the
    //game is over.
    void playGame();
};
