#ifndef RESPONSE_H
#define RESPONSE_H

#include "code.h"

//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file includes the definition of the response class for project 1b.
//The implementations for this class can be found in response.cpp

class response
{
private:
    //Correct and incorrect are the two data members of this class.
    int correct;
    int incorrect;
public:
    //simple constructor initializes data members to 0.
    response(int correct = 0, int incorrect = 0)
    {
        this->correct = correct;
        this->incorrect = incorrect;
    }

    //getCorrect returns the correct data member.
    int getCorrect() const
    {
        return correct;
    }

    //setCorrect sets the correct data member.
    void setCorrect(const int &numCorrect)
    {
        correct = numCorrect;
    }

    //getIncorrect returns the incorrect data member.
    int getIncorrect() const
    {
        return incorrect;
    }

    //setIncorrect sets the incorrect data member.
    void setIncorrect(const int &numIncorrect)
    {
        incorrect = numIncorrect;
    }

    //friend function for overloaded == operator to compare responses
    friend bool operator== (const response &lhs, const response &rhs);

    //Friend function for overloaded << operator to print response
    friend ostream& operator<< (ostream& ostr, const response &resp);

};
#endif
