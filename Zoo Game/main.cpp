// Program name: main.cpp
//Date: 10/26/2019
//Author: Max Veregge
//Description: main.cpp contains the driver function main() for the Zoo game. main() creates a Zoo object
//then runs the startGame() and playTurn() member functions of Zoo until the player decides to quit.

#include <iostream>
#include "Animal.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"
#include "Tiger.hpp"
#include "Zoo.hpp"
#include <iostream>

int main()
{
	Zoo zoo;

	zoo.startGame();
	while (zoo.playTurn() != 2) {
		continue;
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
