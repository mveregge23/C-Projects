// Program name: Menu.cpp
// Author: Max Veregge
// Description: This is an implementation of the Menu class to be used by a program requiring user input.

#include "Menu.h"

// Menu constructor creates a new map of options and a new int userChoice
Menu::Menu() {

	options = new std::map<int, std::string>;
	userChoice = new int;

}

// Menu destructor ensures the dynamically managed options and user choice are destroyed after the Menu goes out of scope
Menu::~Menu() {
	delete options;
	delete userChoice;
}

// addOption creates a new option in the options map using an integer (int c) and string (std::string desc)
void Menu::addOption(int c, std::string desc) {
	(*options).insert({ c, desc });
}

// open opens the menu using the options that have been added to the menu, asks the user to provide input, then validates
// it and returns it to the program that opened the menu
int Menu::open() {

	//initialize the user input variable
	std::string strChoice;

	std::cout << "Welcome to the program! Your options are: \n";

	//print the options
	for (std::map<int, std::string>::iterator it = (*options).begin(); it != (*options).end(); it++) {
		std::cout << it->first << ". " << it->second << '\n';
	}

	std::cout << "Please type a number and click enter to select an option: ";

	//get the user input and store to strChoice
	std::getline(std::cin, strChoice);

	//validate the input and get new input until it is validated
	while (!validateInput(strChoice)) {

		std::cin.clear();

		std::cout << strChoice << " is not a valid option! Please try again. Your options are: \n";
		
		for (std::map<int, std::string>::iterator it = (*options).begin(); it != (*options).end(); it++) {
			std::cout << it->first << ". " << it->second << '\n';
		}

		std::cout << "Please type a number and click enter to select an option: ";

		std::getline(std::cin, strChoice);

	}

	//store the converted input to the userChoice and return it
	*userChoice = convertInput(strChoice);

	return *userChoice;
}

// validateInput takes a string and checks that it is not empty, that every character is a digit, and that
// its int equivalent is an available option in the menu. If all of these conditions are met, it returns true,
// otherwise it returns false
bool Menu::validateInput(std::string input) {

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

	//convert to integer and check that it is in the menu as an available option
	int intInput = convertInput(input);
	std::map<int, std::string>::iterator check = (*options).find(intInput);
	if (check == (*options).end()) {
		return false;
	}

	//if all conditions are true, return true
	return true;
}


// convertInput takes a string and attempts to convert it to an integer. If successful it returns the converted
// integer, otherwise it returns 0
int Menu::convertInput(std::string input) {

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
