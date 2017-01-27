//humanGuess() reads a guess from the keyboard and returns a code object
//that represents the guess.  Inputs are validated to be the right length
//and to be in range by the code constructor called.
code mastermind::humanGuess() {
	cout<<"Enter a guess leaving a space between each digit: ";

	int digit=0;//variable to hold value of each digit
	vector<int> guessVector;//Vector to store partial guess code

	//iterate over all digits in code
	for (int i=0; i<secretCode.getLength(); i++)
	{
		cin>>digit;
		guessVector.push_back(digit);
	}//end of for loop

	//call code constructor to make new code object and validate that inputs
	//are in given range.
	code guess(guessVector,secretCode.getMaxValue());
	return guess;
}//end of function

//getResponse() is passed a guess code, and creates a response object using
//the guess code and secret code as arguments for the response
//constructor.  Processing codes into response is done in response
//constructor because there should never be a response created that is not from
//codes.
response getResponse(const code &guessCode) {
	response checkGuess(guessCode,this->secretCode);
	return response;
}//end of function

//isSolved() is passed a response and returns true if the response is the
//indicates that the code has been guessed
bool isSolved(const response &checkResponse) {
	//by default, game continues
	bool solved = false;

	//check if number correct in response is same as length of secret code.
	if(checkResponse.getCorrect()==this->secretCode.getLength())
	{
		solved = true;
	}
	return solved;
}//End of function

//playGame() initializes a random code, prints it to the screen, then
//iteratively gets a guess from the user and prints the response until the
//game is over.
void playGame() {

	//print secret code (for tests only, disable for playing)
	secretCode.printCode();

	bool won = false; //bool for if guess is correct set to false by default
	for (int i=0; i<10; i++)
	{

		//Let user input a guess
		code guess = humanGuess();

		//determine response to guess
		response guessResponse= getResponse(guess);

		won = isSolved(guessResponse);
	}

	if (won == true)
	{
		cout<<"You Have Won!!!"<<endl;
	}

	else
	{
		cout<<"Sorry, you lost..."<<endl;
	}
}

