/* Project #1
 * Zachary Neveu, neveu.z@husky.neu.edu
 * Jake Dec, dec.j@husky.neu.edu.
 *
 * This file contains the definition of the code class.  Implementations for the member functions of this class can be found in code.cpp */

#ifndef CODE_H
#define CODE_H

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
    int getRange()
    {
        return m;
    };

	//simple function to return size of a codeVector.
    int getLength()
    {
        return codeVector.size();
    };
    int getDataAt(int index)
    {
        return codeVector.at(index);
    };
    code(int codeLen, int MaxValue);//Simple constructor
    code(vector<int> &setVector, int MaxValue);
    const vector<int> viewCode()
    {
        return codeVector;
    }; //simple function to get data
    const int checkCorrect(code guess); //Const so cannot edit code
    const int checkIncorrect(code guess); //Const so cannot edit code
};

#endif
