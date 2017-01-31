// Project #1
// Zachary Neveu, neveu.z@husky.neu.edu
// Jake Dec, dec.j@husky.neu.edu.
//
// This file contains the definition of the code class.  Implementations for
// the member functions of this class can be found in code.cpp

#ifndef CODE_H
#define CODE_H

#include<vector>

using namespace std; //using standard name space

class code
{
private:
    vector<int> codeVector; //Data member of the class

    int n; //n is number of digits in code
    int m; //m is maximum value of each digit

    // randInit takes the code length n, and maximum digit value m as inputs and
    // generates a code within these parameters.
    // randInit() Called by constructor, not accessible by user.
    void randInit();
public:
    //simple function used to get max digit size of secret code
    int getMaxValue()
    {
        return m;
    }

    //simple function to return size of a codeVector.
    int getLength()
    {
        return codeVector.size();
    };

    //Length and Range Constructor calls randInit to generate a random
    //code. This constructor used for secret code.
    code(int codeLen = 0, int MaxValue = 0);

    //  Vector Constructor takes vector as input and passes it to the new code
    //  object as its code member. If digits of vector are out of range, user
    //  is notified and program continues.
    // Constructor used for guess code when codeVector is known.
    code(const vector<int> &setVector, int MaxValue);

    // checkCorrect returns how many digits in the guess match the digits in
    // the code both in value and in position.  Check Correct also validates
    // that all digits of the input are within the specified range
    const int checkCorrect(const code &guess);   //Const so cannot edit code

    // checkIncorrect returns the number of digits in the guess that are in the
    //code but in the wrong position.
    const int checkIncorrect(const code &guess); //Const so cannot edit code

    //Function to print the code object stored in a mastermind object
    const void printCode();
};

#endif

