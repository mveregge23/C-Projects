// Program name: Board.h
// Author: Max Veregge
// Description: The Board class represent a dynamic 2-D array (char** board) through which an Ant (Ant ant) object can move. 
// The rows (int rows) and columns (int cols) in the class should be used to dynamically define the 2-D array and the start row 
// (int startRow) and start column (int startColumn) should be used initialize the position of the ant. Each step of the simulation
// should move the ant (int moveAnt) and change the color of the current spot (void changeColor) to white (' ') or black ('#'). The
// board can be printed after any step (void printBoard). Once the steps (int steps) of the simulation reach zero, the simulation
// should stop.


#ifndef BOARD_H
#define BOARH_H

#include "Ant.h"
#include <iostream>

class Board {
	private:
		char** board;
		int rows;
		int cols;
		int steps;
		Ant ant;
	public:
		Board(int rows, int cols, int startRow, int startCol, int steps);
		~Board();
		void changeColor(Location l);
		int moveAnt();
		void printBoard();
};

#endif