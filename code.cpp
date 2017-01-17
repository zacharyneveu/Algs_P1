/* Project #1
 * Zachary Neveu, neveu.z@husky.neu.edu, (207) 607-9005)
 * Jake Dec, dec.j@husky.neu.edu
 *
 * This file (code.cpp) contains the implementations of the member functions of the
 * code class defined in code.h */


#include"code.h" //Class definition file
#include<vector> //necessary to store code as a vector
#include<iostream> //needed for basic input and output
#include<cstdlib> //Include this for random generator

/* Constructor calls randInit to generate a random code. */
code::code(int n = 0, int m = 0)
{
    randInit(n, m);
    cout << "Code Generated!" << endl;
}//End constructor

/* randInit takes the code length n, and maximum digit value m as inputs and generates
 * a code within these parameters. */
void code::randInit(int n = 0, int m = 0)
{

    vector<int> codeRoot; //vector variable to store code in

    //For loop iterates over each digit of code
    for (int i = 0; i < n; i++)
    {
        //generate random value in range [0,m]
        int digit = rand() % m;

        codeRoot.push_back(i);
    }

    //Assign code data member to value created.
    code = codeRoot;
}//End randInit Function

/* checkCorrect returns how many digits in the guess match the digits in the code both
 * in value and in position */
const int code::checkCorrect(code guess)
{
    int numCorrect = 0; //int to store total correct

    // for iterates over each digit in code/guess
    for (int i; i <= n; i++)
    {
        if (code[i] == guess[i])
        {
            numCorrect += 1;
        }
    }

    return numCorrect;
}//end checkCorrect function

/* checkIncorrect returns the number of digits in the guess that are in the code but in the wrong position. */
const int code::checkIncorrect(code guess)
{
}
