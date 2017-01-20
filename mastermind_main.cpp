/* Project #1
 * Zachary Neveu, neveu.z@husky.neu.edu, (207) 607-9005)
 * Jake Dec, dec.j@husky.neu.edu
 *
 * This file contains the main function of a game of Mastermind.  The user is asked to specify the length of the code, which the program generates, then the user is given ten tries to guess the code based on responses from the program.
 * */

#include<iostream> //standard inputs and outputs
#include<vector> //necessary to store code as vector
#include "code.h" //user made file with code class
#include "code.cpp"

#define ROUNDS 4 //Number of rounds here so it is accessible

using namespace std; //standard name space

int main()
{
    int length, maxDig; //n=code length, m=max digit value
    cout << "Enter Code Length: " << endl;
    cin >> length;
    cout << "Enter Maximum Digit Value: " << endl;
    cin >> maxDig;

    //initialize the code to be guessed within the specified parameters
    code userCode(length, maxDig);

    for (int j = 1; j <= ROUNDS; j++)
    {
        vector<int> guessVector; //Vector to store guess
        int input; //stores each digit of guess
        cout << "Enter Guess One Digit at a Time" << endl;

        for (int i = 0; i < userCode.getLength(); i++)
        {
            //Next two lines for debugging only
            //cout<<"i= "<<i<<endl;
            //cout<<"usercode length= "<<userCode.getLength()<<endl;

            input = 0; //Make sure input is zero
            cin >> input;

            if (input >= userCode.getRange())
            {
                cout << "That digit cannot be in the code." << endl;
                cout << "Please re-enter a valid input" << endl;
                i--; //go back one step in for loop to redo input
                continue; //return to top of the loop
            }
            else
            {
                guessVector.push_back(input); //Set input to end of vector
            }
        }//end for loop

        code guess(guessVector); //initialize code object for guess vector
        cout << "size of guess vector is: " << guessVector.size() << endl;

        //check number of correct digits
        int correct = userCode.checkCorrect(guess);
        //int incorrect = userCode.checkIncorrect(guess);

        if (correct < userCode.getLength())
        {
            //print number of correct digits
            cout << "Correct: " << correct << endl;
            //cout << "Incorrect: " << incorrect << endl;
        }

        else //correct==n && tries<10
        {
            cout << "You Win!!" << endl;
            break;
        }

    }//End For Loop for Guesses
}//End Main Function
