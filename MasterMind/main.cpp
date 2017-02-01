// Project #1
// Zachary Neveu, neveu.z@husky.neu.edu
// Jake Dec, dec.j@husky.neu.edu

// This file contains the testing conditions for part A of the Mastermind
// project. It created a length 5 vector with the range [0,10) and runs the
// three provided test cases against the code.

#include<iostream> //standard inputs and outputs
#include<vector> //necessary to store code as vector
#include "code.h" //user made file with code class
#include "mastermind.h" //model for mastermind game
#include "response.h" //contains class for user response

void getCodeValues(int &n, int &m);

int main()
{
    int n, m; //code length and range

    //get the desired code values from the user
    getCodeValues(n, m);

    //create the mastermind object
    mastermind game(n, m);

    //start the game, print the code
    game.playGame();

	//wait for user acknowledge
	system("pause");

    return 0;
}//End Main Function

void getCodeValues(int &n, int &m)
{

    //Validate that n is a reasonable value
    while (n <= 0)
    {
        cout << "What is the desired length of the code: " << endl;
        cin >> n;
    }

    //validate that m is a reasonable value
    while (m <= 0)
    {
        cout << "What is the desired range for the code [0,m): " << endl;
        cin >> m;
    }
}


