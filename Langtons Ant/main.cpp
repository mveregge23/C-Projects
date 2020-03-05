// Program name: main.cpp
// Author: Max Veregge
// Description: main.cpp uses the Menu, Board, and Ant classes to run a Langton's Ant simulation. There are two functions 
// defined in main.cpp (isValidInput, convInput) which are used to validate user input to the simulation. To run the simulation,
// run the main module and enter 1 to start the simulation. After input is gathered and validated, the Board and Ant classes
// are instantiated and the simulation is run. After running the simulation the user has the option to run the simulation again, 
// or quit the program.

#include <iostream>
#include <sstream>
#include "Ant.h"
#include "Board.h"
#include "Menu.h"
#include <string>

//Declaring input validation & conversion functions
bool isValidInput(std::string);
int convInput(std::string);

int main()
{
	
	//Defining maximum steps in simulation
	const int MAX_STEPS = 100;

	//Creating and opening main menu
	Menu menu;
	menu.addOption(1, "Start the Langton's Ant simulation");
	menu.addOption(2, "Quit");
	int selection = menu.open();

	//If user wants to run the simulation, continue
	while (selection != 2) {

		std::cout << "\nOk! Let\'s get started. First, please enter a positive integer for the number of rows on the board: ";

		//Gathering and validating user input for rows on board
		std::string strRows;
		std::getline(std::cin, strRows);
		while (!(isValidInput(strRows))) {
			std::cin.clear();
			std::cout << "\n" << strRows << " is not a valid input. You need to enter a positive integer, try again: ";
			std::getline(std::cin, strRows);
		}

		int intRows = convInput(strRows);

		std::cout << "\nYou entered " << intRows << " rows";

		std::cout << "\nNext, please enter a positive integer for the number of columns on the board: ";

		//Gathering and validating user input for columns on board
		std::string strCols;
		std::getline(std::cin, strCols);
		while (!(isValidInput(strCols))) {
			std::cin.clear();
			std::cout << "\n" << strCols << " is not a valid input. You need to enter a positive integer, try again: ";
			std::getline(std::cin, strCols);
		}

		int intCols = convInput(strCols);

		std::cout << "\nYou entered " << intCols << " columns";

		std::cout << "\nGreat! Please enter a positive integer for the number of steps in the simulation: ";

		//Gathering and validating user input for number of steps in simulation
		std::string strSteps;
		std::getline(std::cin, strSteps);
		while (!(isValidInput(strSteps)) || convInput(strSteps) > MAX_STEPS) {
			std::cin.clear();
			std::cout << "\n" << strSteps << " is not a valid input. You need to enter a positive integer less than or equal to " << MAX_STEPS << ", try again: ";
			std::getline(std::cin, strSteps);
		}

		int intSteps = convInput(strSteps);

		std::cout << "\nYou entered " << intSteps << " steps";

		std::cout << "\nAlmost there. Please enter a positive integer between 1 and the number of rows on the board for the starting row of the ant: ";

		//Gathering and validating user input for starting row of ant
		std::string strStartRow;
		std::getline(std::cin, strStartRow);
		while (!(isValidInput(strStartRow)) || convInput(strStartRow) < 1 || convInput(strStartRow) > intRows) {
			std::cin.clear();
			std::cout << "\n" << strStartRow << " is not a valid input. You need to enter positive integer between 1 and the number of rows on the board, try again: ";
			std::getline(std::cin, strStartRow);
		}

		int intStartRow = convInput(strStartRow);

		std::cout << "\nYou entered " << intStartRow << " as the starting row";

		std::cout << "\nLast step! Please enter a positive integer between 1 and the number of columns on the board for the starting column of the ant: ";
		
		//Gathering and validating user input for starting column of ant
		std::string strStartCol;
		std::getline(std::cin, strStartCol);
		while (!(isValidInput(strStartCol)) || convInput(strStartCol) < 1 || convInput(strStartCol) > intCols) {
			std::cin.clear();
			std::cout << "\n" << strStartCol << " is not a valid input. You need to enter positive integer between 1 and the number of columns on the board, try again: ";
			std::getline(std::cin, strStartCol);
		}

		int intStartCol = convInput(strStartCol);

		std::cout << "\nYou entered " << intStartCol << " as the starting column";

		std::cout << "Alright! Let\'s do it!\n";

		//Initializing the board
		Board b(intRows, intCols, intStartRow - 1, intStartCol - 1, intSteps);

		//Running the simulation
		while (b.moveAnt() > 0) {
			b.printBoard();
		}

		b.printBoard();

		//Reopening the main menu
		selection = menu.open();

	}

	return 0;
}


// isValidInput takes a string and checks its validity for use in the simulation by ensuring it is not empty
// and it only contains digits. If those two conditions are met, it returns true, otherwise it returns false
bool isValidInput(std::string input) {
	
	//check that length is not equal to 0
	if (input.length() == 0) {
		return false;
	}

	//check that every character is a digit
	for (unsigned int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
			return false;
		}
	}

	return true;
}

// convInput takes a string and converts it to an integer. If the conversion is successful, it returns the output,
// otherwise it returns 0
int convInput(std::string input) {

	//convert string to int
	std::istringstream iss(input);
	int output;
	iss >> output;

	//check that conversion was successful
	if (iss.fail()) {
		return 0;
	}

	return output;
}
