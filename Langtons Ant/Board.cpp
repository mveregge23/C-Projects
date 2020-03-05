// Program name: Board.cpp
// Author: Max Veregge
// Description: This is an implementation of the Board class to be used in the Langton's Ant simulation.

#include "Board.h"

// Board constructor using input numRows and numCols to initialize the 2-D board, and startRow and startCol 
// to initialize the position of the ant. numSteps is stored as an incrementer to track the steps in the simulation
Board::Board(int numRows, int numCols, int startRow, int startCol, int numSteps) {
	
	rows = numRows;
	cols = numCols;

	//dynamically build the 2-D board
	board = new char* [numRows];
	
	for (int i = 0; i < numRows; i++) {
		board[i] = new char[numCols];
	}

	for (int i = 0; i < numRows; i++) {
		std::fill(board[i], board[i] + numCols, ' ');
	}

	steps = numSteps;

	//create the Ant to move about the board
	ant = Ant(Location(startRow, startCol), NORTH);

}

// Board destructor to ensure dynamically allocated memory for board is freed once Board object goes out of scope
Board::~Board() {

	for (int i = 0; i < cols; i++) {
		delete[] board[i];
	}

	delete[] board;

}

// changeColor takes a Location object L to determine what the current color of that location on the board is, and
// change it to the opposite
void Board::changeColor(Location l){

	//check color of current Location l change to opposite
	if (board[l.getX()][l.getY()] == '#') {
		board[l.getX()][l.getY()] = ' ';
	}

	else {
		board[l.getX()][l.getY()] = '#';
	}

}

// moveAnt checks the color of current location and changes the orientation of the ant accordingly, then changes
// the color of the spot and moves the ant in the direction of its current orienation
int Board::moveAnt() {

	// if color of current spot on board is black ('#'), rotate counter-clockwise and move ant
	if (board[ant.getLocation().getX()][ant.getLocation().getY()] == '#') {

		// if orientation enum is equal to zero, set it to 3
		if (ant.getOrientation() == 0) {

			ant.setOrientation(Orientation(3));
			changeColor(ant.getLocation());

		}
		
		// otherwise subtract 1 
		else {

			ant.setOrientation(Orientation(ant.getOrientation() - 1));
			changeColor(ant.getLocation());

		}

		std::cout << "Current space changed to white\n";
		std::cout << "Orientation rotated 90 degrees counter-clockwise to: " << ant.getOrientation() << '\n';

	}

	// otherwise color of current spot must be white (' '), rotate clockwise and move ant
	else {

		// if orientation enum is equal to 3, set it to 0
		if (ant.getOrientation() == 3) {

			ant.setOrientation(Orientation(0));
			changeColor(ant.getLocation());

		}

		// otherwise add 1
		else {

			ant.setOrientation(Orientation(ant.getOrientation() + 1));
			changeColor(ant.getLocation());

		}

		std::cout << "Current space changed to black\n";
		std::cout << "Orientation rotated 90 degrees clockwise to: " << ant.getOrientation() << '\n';

	}

	// depending on the ant's orientation, check for certain edge cases and move appropriately
	switch (ant.getOrientation()) {

		// if ant is facing north, check for edge cases and move appropriately
		case NORTH:

			// if ant is already on first row of board, move it to the last row and keep the column the same
			if (ant.getLocation().getX() == 0) {

				ant.setLocation(Location(rows - 1, ant.getLocation().getY()));
				std::cout << "New xC: " << ant.getLocation().getX() << ", new yC: " << ant.getLocation().getY() << '\n';

			}

			// otherwise subtract one from the row and keep the column the same
			else {
				ant.setLocation(Location(ant.getLocation().getX() - 1, ant.getLocation().getY()));
				std::cout << "New xC: " << ant.getLocation().getX() << ", new yC: " << ant.getLocation().getY() << '\n';
			}

			break;

		// if ant is facing east, check for edge cases and move appropriately
		case EAST:

			// if ant is already on the last column of board, move it to the first column and keep the row the same
			if (ant.getLocation().getY() == cols - 1) {

				ant.setLocation(Location(ant.getLocation().getX(), 0));
				std::cout << "New xC: " << ant.getLocation().getX() << ", new yC: " << ant.getLocation().getY() << '\n';

			}

			// otherwise add one to the column and keep the row the same
			else {

				ant.setLocation(Location(ant.getLocation().getX(), ant.getLocation().getY() + 1));
				std::cout << "New xC: " << ant.getLocation().getX() << ", new yC: " << ant.getLocation().getY() << '\n';

			}
			break;

		// if ant is facing south, check for edge cases and move appropriately
		case SOUTH:

			// if ant is already on the last row of the board, move it to the first row and keep the column the same
			if (ant.getLocation().getX() == rows - 1) {

				ant.setLocation(Location(0, ant.getLocation().getY()));
				std::cout << "New xC: " << ant.getLocation().getX() << ", new yC: " << ant.getLocation().getY() << '\n';

			}

			// otherwise subtract one from the row and keep the column the same
			else {

				ant.setLocation(Location(ant.getLocation().getX() + 1, ant.getLocation().getY()));
				std::cout << "New xC: " << ant.getLocation().getX() << ", new yC: " << ant.getLocation().getY() << '\n';
			
			}
			
			break;
		
		// if ant is facing west, check for edge cases and move appropriately
		case WEST:

			//if ant is already on the first column of the board, move it to the last column and keep the row the same
			if (ant.getLocation().getY() == 0) {

				ant.setLocation(Location(ant.getLocation().getX(), cols - 1));
				std::cout << "New xC: " << ant.getLocation().getX() << ", new yC: " << ant.getLocation().getY() << '\n';
			
			}
			
			//otherwise subtract one from the column and keep the row the same
			else {

				ant.setLocation(Location(ant.getLocation().getX(), ant.getLocation().getY() - 1));
				std::cout << "New xC: " << ant.getLocation().getX() << ", new yC: " << ant.getLocation().getY() << '\n';
			
			}
			
			break;
	}

	//increment the number of steps and return it to the function moving the ant
	return --steps;
}

// printBoard prints a visual representation of the board. The spot with the ant on it is represented by a '*', white spots
// are represented by a ' ', and black spots are represented by a '#'.
void Board::printBoard() {
	
	std::cout << "Board state with " << steps << " steps remaining:\n"; 

	//print top boundary of board
	for (int k = 0; k < cols + 2; k++) {
		std::cout << '-';
	}
	std::cout << '\n';

	for (int i = 0; i < rows; i++) {

		//print leftmost boundary of board
		std::cout << '|';

		for (int j = 0; j < cols; j++) {

			if (ant.getLocation().getX() == i && ant.getLocation().getY() == j) {
				std::cout << '*';
			}

			else {
				std::cout << board[i][j];
			}

		}

		//print rightmost boundary of board
		std::cout << "|\n";

	}

	//print bottom boundary of board
	for (int k = 0; k < cols + 2; k++) {
		std::cout << '-';
	}
	std::cout << '\n';
}