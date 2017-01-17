/* Project #1
 * Zachary Neveu, neveu.z@husky.neu.edu, (207) 607-9005)
 * Jake Dec, dec.j@husky.neu.edu.
 *
 * This file contains the definition of the code class.  Implementations for the member functions of this class can be found in code.cpp */

#ifndef CODE_H
#define CODE_H

class code
{
private:
    vector<int> code; //Data member of the class

    //Called by constructor, not accessible by user.
    void randInit(int n = 0, int m = 0);
public:
    //constructor defaults to 0. n=Code length, m=range of digits
    code(int n = 0, int m = 0);
    const int checkCorrect(code guess); //Const so cannot edit code
    const int checkIncorrect(code guess); //Const so cannot edit code
};

#endif
