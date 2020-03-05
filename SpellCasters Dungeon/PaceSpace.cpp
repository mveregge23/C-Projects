// Program name: PaceSpace.cpp
// Date: 12/9/19
// Author: Max Veregge
// Description: PaceSpace.cpp contains an implementation of the derived
// PaceSpace class. PaceSpace inherits most data members and functions
// from the Space parent class, but defines its own stepBoost data member, and 
// a constructor and accessor to manage it. 

#include "PaceSpace.hpp"

//constructor inherits behavior from the Space constructor, and
//accepts an integer to initialize the stepBoost data member
PaceSpace::PaceSpace(int pb) : Space()
{
	this->paceBoost = pb;
	this->st = PACES;
}

//interact tells the user what will happen on this space
void PaceSpace::interact()
{
	std::cout << "You found " << this->paceBoost << " paces! "
		<< "Press enter to pick them up...";
	std::cin.ignore();
}

//getStepBoost is an accessor for the stepBoost data member
int PaceSpace::getPaceBoost()
{
	return this->paceBoost;
}