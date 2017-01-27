//Contains the longer methods of the response class.

#include "response.h"
#include <iostream>
#include <string>


bool response::operator == (response other) {
	return this->getCorrect() == other.getCorrect &&
		   this->getIncorrect == other.getIncorrect;
}


ostream& operator<< (ostream& ostr, const response& resp) {
	ostr << "Number of correct: " << resp.getCorrect() << endl;
	ostr << "Number of incorrect: " << resp.getIncorrect() << endl;
	return ostr;
}