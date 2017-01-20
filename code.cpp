/* Project #1
 * Zachary Neveu, neveu.z@husky.neu.edu, (207) 607-9005)
 * Jake Dec, dec.j@husky.neu.edu
 *
 * This file (code.cpp) contains the implementations of the member functions of the
 * code class defined in code.h */


#include "code.h" //Class definition file
#include<vector> //necessary to store code as a vector
#include<iostream> //needed for basic input and output
#include<cstdlib> //Include this for random generator

using namespace std; //using standard name space

/* Length and Range Constructor calls randInit to generate a random code. */
code::code(int codeLen, int MaxDig)
{
    n = codeLen; //Set n for code object
    m = MaxDig; //Set m of code object
    randInit(); //Initialize with random integers in range
    cout << "Code Generated!" << endl;
}//End constructor

/*  Vector Constructor takes vector as input and passes it to the new code
 *  object as its code member.  */
code::code(vector<int> &setVector)
{
    n = setVector.size(); //Size of vector is size of code
    m = 9; //Unknown Max Dig size, but this doesn't matter for this.
    codeVector = setVector; //Code data is vector passed to function
}//End vector constructor


/* randInit takes the code length n, and maximum digit value m as inputs and generates
 * a code within these parameters. */
void code::randInit()
{

    //For loop iterates over each digit of code
    for (int i = 0; i < n; i++)
    {
        //generate random value in range [0,m-1]
        int digit = rand() % m;

        //Store random values in code vector
        codeVector.push_back(digit);
    }

}//End randInit Function

/* checkCorrect returns how many digits in the guess match the digits in the code both
 * in value and in position */
const int code::checkCorrect(code guess)
{
    int numCorrect = 0; //int to store total correct

    if (getLength() == guess.getLength()) //Make sure vector was entered completely
    {
        // for iterates over each digit in code/guess
        for (int i; i < n; i++)
        {
            //Check if code vector equals guess vector at index
            if (getDataAt(i) == guess.getDataAt(i))
            {
                numCorrect += 1;
            }
        }

        return numCorrect;
    }//End if statement
    else
    {
        cout << "Sorry Entering Guess Failed" << endl;
        return 0;
    }//end of else statement
}//end checkCorrect function

/* checkIncorrect returns the number of digits in the guess that are in the code but in the wrong position. */
//const int code::checkIncorrect(code guess)
