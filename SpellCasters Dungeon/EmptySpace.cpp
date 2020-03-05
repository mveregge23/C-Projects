// Program name: EmptySpace.cpp
// Date: 12/9/19
// Author: Max Veregge
// Description: EmptySpace.cpp contains a specification for the derived
// EmptySpace class. EmptySpace inherits all of its data members and 
// functions from the Space parent class, but defines its own constructor
// to initialize the type appropriately and defines the virtual interact
// function.

#include "EmptySpace.hpp"

//default constructor inherits behavior from parent constructor and
//augments it to define type
EmptySpace::EmptySpace() : Space()
{
	this->st = EMPTY;
}

//interact tells the user what will happen on this space
void EmptySpace::interact()
{
	std::cout << "You are on an empty space. Press enter continue...";
	std::cin.ignore();
}