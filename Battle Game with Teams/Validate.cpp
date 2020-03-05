// Program name: Validate.cpp
// Date: 11/14/19
// Author: Max Veregge
// Description: Validate.cpp contains implementations of the functions in Validate.hpp. It includes
// a function validateInput to ensure that the user's input is an integer, and it includes a function
// convertInput to convert the user's input from a string to an integer

#include "Validate.hpp"

// validateInput takes a string and checks that it is not empty, that every character is a digit, and that
// its int equivalent is an available option in the menu. If all of these conditions are met, it returns true,
// otherwise it returns false
bool validateIntInput(std::string input) {

	//check that input isn't blank
	if (input.length() == 0) {
		return false;
	}

	//check that every character is a digit
	for (unsigned int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
			return false;
		}
	}

	//if all conditions are true, return true
	return true;
}


// convertInput takes a string and attempts to convert it to an integer. If successful it returns the converted
// integer, otherwise it returns 0
int convertInputToInt(std::string input) {

	//perform conversion
	std::istringstream iss(input);
	int output;
	iss >> output;

	//if conversion fails, return 0
	if (iss.fail()) {
		return 0;
	}

	//otherwise return converted integer
	return output;
}

// getInput gets the user's input and validates that it is an integer using the validateInput and convertInput functions
int getIntInput() {

	//initialize the user input variable
	std::string strInput;

	//get the user input and store to strChoice
	std::getline(std::cin, strInput);

	//validate the input and get new input until it is validated
	while (!validateIntInput(strInput)) {
		std::cin.clear();
		std::cout << strInput << " is not a valid input! Please try again. Enter an integer: ";
		std::getline(std::cin, strInput);
	}

	//store the converted input to the userInput and return it
	int userInput = convertInputToInt(strInput);
	return userInput;
}