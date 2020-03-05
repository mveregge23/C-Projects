// Date: 12/9/19
// Author: Max Veregge
// Description: HealthSpace.hpp contains an implementation of the derived
// HealthSpace class. HealthSpace inherits most data members and functions
// from the Space parent class, but defines its own healthBoost data member, and 
// a constructor and accessor to manage it. 

#include "HealthSpace.hpp"

//constructor inherits behavior from the Space constructor, and
//accepts an integer to initialize the healthBoost data member
HealthSpace::HealthSpace(int hb) : Space()
{
	this->healthBoost = hb;
	this->st = HEALTH;
}

//interact tells the user what will happen on this space
void HealthSpace::interact()
{
	std::cout << "You found " << this->healthBoost << " health! "
		<< "Press enter to pick it up...";
	std::cin.ignore();
}

//getHealthBoost is an accessor for the healthBoost data member
int HealthSpace::getHealthBoost()
{
	return this->healthBoost;
}