//Contains the longer methods of the response class.

#include "response.h"
#include <iostream>
#include <string>

//Overloaded operator == returns true if the lhs and rhs responses are equal,
//else it returns false.  NOTE: this is not used in the code anywhere, it is
//simply a requirement of the project
bool operator == (const response &lhs, const response &rhs)
{
    return lhs.correct == rhs.correct && lhs.incorrect == rhs.incorrect;
}


//Overloaded operator << displays the values stored in a response.  This is used
//in the playGame() function.
ostream& operator<< (ostream& ostr, const response& resp)
{
    ostr << "Number of correct: " << resp.getCorrect() << endl;
    ostr << "Number of incorrect: " << resp.getIncorrect() << endl;
    return ostr;
}
