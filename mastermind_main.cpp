/* Project #1
 * Zachary Neveu, neveu.z@husky.neu.edu, (207) 607-9005)
 * Jake Dec, dec.j@husky.neu.edu
 *
 * This file contains the main function of a game of Mastermind.  The user is asked to specify the length of the code, which the program generates, then the user is given ten tries to guess the code based on responses from the program.
 * */

#include<iostream> //standard inputs and outputs
#include<vector> //necessary to store code as vector

using namespace std; //standard name spcace

int main()
{
    int n, m; //n=code length, m=max digit value
    cout << "Enter Code Length: " << endl;
    cin >> n;
    cout << "Enter Maximum Digit Value: " << endl;
    cin >> m;

//initialize the code to be guessed within the specified parameters
    code userCode(n, m);

    for (int i = 1; i <= 10; i++)
    {
        vector<int> guess;
        int input;
        cout << "Enter Guess One Digit at a Time" << endl;

        for (int i = 0; i < n; i++)
        {
            input = 0; //Make sure input is zero
            cin >> input;
            guess.push_back(input); //Set input to end of vector
        }

        //check number of correct digits
        int correct = userCode.checkCorrect(guess);
        int incorrect = userCode.checkIncorrect(guess);

        if (correct < n)
        {
            //print number of correct digits
            cout << "Correct: " << correct << endl;
            cout << "Incorrect: " << incorrect << endl;
        }

        else //correct==n && tries<10
        {
            cout << "You Win!!" << endl;
        }

    }//End For Loop for Guesses
}//End Main Function
