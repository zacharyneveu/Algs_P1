//Project #1
// Zachary Neveu, neveu.z@husky.neu.edu
// Jake Dec, dec.j@husky.neu.edu

// This file contains the main function of a game of Mastermind.  The user is
// asked to specify the length of the code, which the program generates, then
// the user is given ten tries to guess the code based on responses from the
// program.

#include<iostream> //standard inputs and outputs
#include<vector> //necessary to store code as vector
#include "code.h" //user made file with code class
#include "code.cpp" //user made cpp file

#define ROUNDS 10 //Number of rounds here so it is accessible

using namespace std; //standard name space

int main()
{
    //Get inputs for Random Generator
    int length, MaxValue; //n=code length, m=max digit value
    cout << "Enter Code Length: " << endl;
    cin >> length;
    cout << "Enter Maximum Digit Value: " << endl;
    cin >> MaxValue;

    //initialize the code to be guessed within the specified parameters
    code secretCode(length, MaxValue);

    //Iterate over rounds of the game
    for (int j = 0; j < ROUNDS; j++)
    {
        vector<int> guessVector; //Vector to store guess
        int input; //stores each digit of guess
        cout << "Enter Guess One Digit at a Time" << endl;

        for (int i = 0; i < secretCode.getLength(); i++)
        {
            input = 0; //Make sure input is zero
            cin >> input; //store individual digit
            guessVector.push_back(input); //Add digit to vector
        }//end for loop for input

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

    }//End For Loop for Guesses
}//End Main Function
