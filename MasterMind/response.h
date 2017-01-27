#pragma once

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
    response(code guess, code secret)
    {
		this->correct = secret.checkCorrect(guess);
		this->incorrect = secret.checkIncorrect(guess);
    }

    //getCorrect returns the correct data member.
    int getCorrect() const;
    {
        return correct;
    }

    //setCorrect sets the correct data member.
    void setCorrect(const int &numCorrect);
    {
        this->correct = numCorrect;
    }

    //getIncorrect returns the incorrect data member.
    int getIncorrect() const;
    {
        return incorrect;
    }

    //setIncorrect sets the incorrect data member.
    void setIncorrect(const int &numIncorrect);
    {
        this->incorrect = numIncorrect;
    }
};
