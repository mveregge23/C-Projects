// Program name: Die.cpp
// Author: Max Veregge
// Description: Die.cpp contains an implementation of the Die class

#include "Die.hpp"

//roll() performs a random roll of the die and returns the number rolled
int Die::roll() const
{
	return std::rand() % sides + 1;
}

//setSides() takes an int and uses it to set the number of sides on the die
void Die::setSides(int sides) {
	this->sides = sides;
}

//Die(int) constructor initializes a die object with a number of sides
Die::Die(int sides) {
	this->setSides(sides);
}

//Die() default constructor performs no initialization
Die::Die() {
	;
}
