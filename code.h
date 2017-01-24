/* Project #1
 * Zachary Neveu, neveu.z@husky.neu.edu
 * Jake Dec, dec.j@husky.neu.edu.
 *
 * This file contains the definition of the code class.  Implementations for
 * the member functions of this class can be found in code.cpp */

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

    //Called by constructor, not accessible by user.
    void randInit();
public:

    //simple function to return size of a codeVector.
    int getLength()
    {
        return codeVector.size();
    };

    //Constructor used for secret code
    code(int codeLen, int MaxValue);

    //Constructor used for guess code when codeVector is known.
    code(const vector<int> &setVector, int MaxValue);

    //function to check how many digits are correct
    const int checkCorrect(const code &guess);   //Const so cannot edit code

    //function to check how many digits are correct but in the wrong place
    const int checkIncorrect(const code &guess); //Const so cannot edit code 
};

#endif
