//Contains the longer methods of the response class.

#include "response.h"
#include <iostream>
#include <string>


bool response::operator == (response other) {
	return this->getCorrect() == other.getCorrect &&
		   this->getIncorrect == other.getIncorrect;
}

string response::operator << () {
	char * result;

	sprintf(result, "Number of Correct: %d\nNumber of Incorrect: %d\n", 
		getCorrect(), getIncorrect());

	return result;
}