// Program name: Die.hpp
// Author: Max Veregge
// Description: Die.hpp contains a specification for the Die class. Die represents a die to be
// used in a typical dice game, where the user can specify the number of sides on the die, and
// perform a random roll of the die.

#ifndef DIE_HPP
#define DIE_HPP
#include <cstdlib>

class Die {
protected:
	int sides;
public:
	virtual int roll() const;
	void setSides(int);
	Die(int);
	Die();
};

#endif